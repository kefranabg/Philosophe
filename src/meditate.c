/*
** meditate.c for meditate.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 20:17:31 2014 abgral_f
** Last update Sat Mar 15 20:24:44 2014 abgral_f
*/

#include		<unistd.h>
#include		<stdlib.h>
#include		"philosophe.h"

void                    put_stick_down(t_philo *philo, int tab_case)
{
  printf(MEDITATING, philo->name);
  pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
  philo->need_to_eat = TRUE;
  pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
  if (philo->stick_left == TRUE)
    {
      pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
      philo->table->sticks[philo->id].used_for_think = FALSE;
      philo->table->sticks[philo->id].used_by = NULL;
      pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
    }
  if (philo->stick_right == TRUE)
    {
      pthread_mutex_lock(&(philo->table->mut_sticks[tab_case]));
      philo->table->sticks[tab_case].used_for_think = FALSE;
      philo->table->sticks[tab_case].used_by = NULL;
      pthread_mutex_unlock(&(philo->table->mut_sticks[tab_case]));
    }
  pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
  philo->stick_right = FALSE;
  philo->stick_left = FALSE;
  pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
}

void                    meditate_case(t_philo *philo, int tab_case)
{
  unsigned int          time;

  if (philo->stick_left == TRUE)
    {
      pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
      philo->table->sticks[philo->id].used_for_think = TRUE;
      pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
      time = 0;
      while (++time != THINK_TIME * 100000
             && philo->table->sticks[philo->id].used_for_think == TRUE)
        usleep(10);
    }
  if (philo->stick_right == TRUE)
    {
      pthread_mutex_lock(&(philo->table->mut_sticks[tab_case]));
      philo->table->sticks[tab_case].used_for_think = TRUE;
      pthread_mutex_unlock(&(philo->table->mut_sticks[tab_case]));
      time = 0;
      while (++time != THINK_TIME * 100000
             && philo->table->sticks[tab_case].used_for_think == TRUE)
        usleep(10);
    }
}

void                    meditate(t_philo *philo)
{
  int                   tab_case;

  tab_case = select_case(philo);
  meditate_case(philo, tab_case);
  put_stick_down(philo, tab_case);
}
