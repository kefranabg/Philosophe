/*
** select_stick.c for select_stick.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 20:16:50 2014 abgral_f
** Last update Sat Mar 15 20:17:18 2014 abgral_f
*/

#include		<stdlib.h>
#include		"philosophe.h"

int                     get_right_stick(t_philo *philo)
{
  int                   tab_case;

  tab_case = select_case(philo);
  pthread_mutex_lock(&(philo->table->mut_sticks[tab_case]));
  if (philo->table->sticks[tab_case].used_by == NULL)
    {
      philo->table->sticks[tab_case].used_by = philo;
      philo->stick_right = TRUE;
      pthread_mutex_unlock(&(philo->table->mut_sticks[tab_case]));
      return (EXIT_SUCCESS);
    }
  if (philo->table->sticks[tab_case].used_by != NULL
      && philo->table->sticks[tab_case].used_for_think == TRUE)
    {
      philo->table->sticks[tab_case].used_by = philo;
      philo->table->sticks[tab_case].used_for_think = FALSE;
      philo->stick_right = TRUE;
      pthread_mutex_unlock(&(philo->table->mut_sticks[tab_case]));
      return (EXIT_SUCCESS);
    }
  pthread_mutex_unlock(&(philo->table->mut_sticks[tab_case]));
  return (EXIT_FAILURE);
}

int                     get_left_stick(t_philo *philo)
{
  pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
  if (philo->table->sticks[philo->id].used_by == NULL)
    {
      philo->table->sticks[philo->id].used_by = philo;
      philo->stick_left = TRUE;
      pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
      return (EXIT_SUCCESS);
    }
  if (philo->table->sticks[philo->id].used_by != NULL
      && philo->table->sticks[philo->id].used_for_think == TRUE)
    {
      philo->table->sticks[philo->id].used_by = philo;
      philo->table->sticks[philo->id].used_for_think = FALSE;
      philo->stick_left = TRUE;
      pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
      return (EXIT_SUCCESS);
    }
  pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
  return (EXIT_FAILURE);
}
