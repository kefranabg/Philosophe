/*
** eat.c for eat.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 20:15:05 2014 abgral_f
** Last update Sat Mar 15 20:25:22 2014 abgral_f
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"philosophe.h"

void                    eat_mutex(t_philo *philo, int tab_case)
{
  pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
  philo->table->sticks[philo->id].used_for_think = FALSE;
  philo->table->sticks[philo->id].used_by = NULL;
  philo->stick_left = FALSE;
  pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
  pthread_mutex_lock(&(philo->table->mut_sticks[tab_case]));
  philo->table->sticks[tab_case].used_for_think = FALSE;
  philo->table->sticks[tab_case].used_by = NULL;
  philo->stick_right = FALSE;
  pthread_mutex_unlock(&(philo->table->mut_sticks[tab_case]));
}

void                    eat(t_philo *philo)
{
  int                   tab_case;

  tab_case = select_case(philo);
  pthread_mutex_lock(&(philo->table->mut_resources));
  if (philo->table->resources > 0)
    {
      printf(EATING, philo->name);
      sleep(EAT_TIME);
      philo->table->resources--;
      eat_mutex(philo, tab_case);
      philo->eaten++;
      philo->need_to_eat = FALSE;
      philo->need_to_sleep = TRUE;
      printf(RICE, philo->table->resources);
    }
  pthread_mutex_unlock(&(philo->table->mut_resources));
}
