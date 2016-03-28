/*
** run_philosophe.c for run_philosophe.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Mar 11 21:51:28 2014 abgral_f
** Last update Fri Mar 21 16:21:45 2014 abgral_f
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<pthread.h>
#include		<unistd.h>
#include		"philosophe.h"

int			circulaire_nb(int nb, t_table *table)
{
  if (nb == table->nb_philo)
    return (0);
  else if (nb < 0)
    return (table->nb_philo - 1);
  else
    return (nb);
}

int			select_case(t_philo *philo)
{
  int			tab_case;

  tab_case = circulaire_nb(philo->id - 1, philo->table);
  return (tab_case);
}

int			run_philosophe(t_table *table)
{
  int			count;
  pthread_t		*threads;
  void			*ret;

  count = 0;
  if ((threads = malloc(sizeof (*threads) * table->nb_philo)) == NULL)
    return (error(MALLOC_ERR));
  pthread_mutex_init(&(table->mut_resources), NULL);
  while (count != table->nb_philo)
    {
      pthread_mutex_init(&(table->mut_sticks[count]), NULL);
      init_sticks(&(table->sticks[count]), count);
      pthread_create(&(threads[count]),
		     NULL, start_dinner, &(table->philo[count]));
      count++;
    }
  count = 0;
  while (count < table->nb_philo)
    {
      pthread_join(threads[count], &ret);
      count++;
    }
  free(threads);
  return (EXIT_SUCCESS);
}
