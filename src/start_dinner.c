/*
** start_dinner.c for start_dinner.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 20:18:37 2014 abgral_f
** Last update Sat Mar 15 20:18:56 2014 abgral_f
*/

#include		<stdlib.h>
#include		"philosophe.h"

void                    dinner_constraints(t_philo *philo)
{
  if (get_left_stick(philo) == EXIT_SUCCESS)
    {
      if (get_right_stick(philo) == EXIT_FAILURE)
        {
          pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
          philo->stick_left = FALSE;
          philo->table->sticks[philo->id].used_by = NULL;
          pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
        }
    }
  if (philo->stick_left == TRUE
      && philo->stick_right == TRUE)
    eat(philo);
}

void                    available_actions(t_philo *philo)
{
  if (philo->eaten < (philo->table->resources_ref / philo->table->nb_philo))
    {
      get_left_stick(philo);
      get_right_stick(philo);
      if (philo->stick_left == TRUE && philo->stick_right == TRUE)
        eat(philo);
      else if ((philo->stick_left == TRUE && philo->stick_right == FALSE)
               ||(philo->stick_left == FALSE && philo->stick_right == TRUE))
        meditate(philo);
    }
  else
    {
      if (get_right_stick(philo) == EXIT_SUCCESS
          || get_left_stick(philo) == EXIT_SUCCESS)
        meditate(philo);
    }
}

void                    *start_dinner(void *tmp)
{
  t_philo               *philo;

  philo = (t_philo *)tmp;
  while (philo->table->resources > 0)
    {
      if (philo->need_to_eat == TRUE)
        dinner_constraints(philo);
      else if (philo->need_to_sleep == TRUE)
        {
          if (philo->stick_left == FALSE && philo->stick_right == FALSE)
            rest(philo);
        }
      else
        available_actions(philo);
    }
  return (NULL);
}
