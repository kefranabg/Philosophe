/*
** sleep.c for sleep.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 20:16:01 2014 abgral_f
** Last update Sat Mar 15 20:25:02 2014 abgral_f
*/

#include		<stdlib.h>
#include		<unistd.h>
#include		"philosophe.h"

void                    rest(t_philo *philo)
{
  printf(SLEEPING, philo->name);
  sleep(SLEEP_TIME);
  pthread_mutex_lock(&(philo->table->mut_sticks[philo->id]));
  philo->need_to_sleep = FALSE;
  pthread_mutex_unlock(&(philo->table->mut_sticks[philo->id]));
}
