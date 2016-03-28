/*
** default_philo.c for default_philo.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 12:55:03 2014 abgral_f
** Last update Sat Mar 15 20:45:34 2014 abgral_f
*/

#include		<stdlib.h>
#include		"philosophe.h"

static char		*name[] =
  {
    "Aymeric",
    "Dellin_a",
    "Pichot_k",
    "Julie",
    "Prash",
    "Aurélie",
    "Ludivine"
  };

int			default_philo(t_table *table)
{
  int			count;

  table->nb_philo = NB_PHIL;
  table->resources_ref = NB_RESOURCES;
  table->resources = NB_RESOURCES;
  if ((table->sticks = malloc(sizeof (*(table->sticks)) * NB_STICKS)) == NULL)
    return (error(MALLOC_ERR));
  if ((table->philo = malloc(sizeof (*(table->philo)) * NB_PHIL)) == NULL)
    return (error(MALLOC_ERR));
  if ((table->mut_sticks = malloc(sizeof (*(table->mut_sticks))
				  * NB_STICKS)) == NULL)
    return (error(MALLOC_ERR));
  count = 0;
  while (count != NB_PHIL)
    {
      init_philo(&(table->philo[count]), count, table, name[count]);
      count++;
    }
  return (EXIT_SUCCESS);
}
