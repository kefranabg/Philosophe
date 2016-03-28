/*
** init.c for init.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Mar 11 23:11:23 2014 abgral_f
** Last update Sat Mar 15 20:48:39 2014 abgral_f
*/

#include		<stdlib.h>
#include		<string.h>
#include		"philosophe.h"

int                     init_table(t_table *table, int count)
{
  table->resources_ref = table->resources;
  table->nb_philo = count - 1;
  if ((table->sticks = malloc(sizeof (*(table->sticks)) * count - 1)) == NULL)
    return (error(MALLOC_ERR));
  if ((table->philo = malloc(sizeof (*(table->philo)) * count - 1)) == NULL)
    return (error(MALLOC_ERR));
  if ((table->mut_sticks = malloc(sizeof (*(table->mut_sticks))
				  * count - 1)) == NULL)
    return (error(MALLOC_ERR));
  return (EXIT_SUCCESS);
}

void			init_philo(t_philo *philo, int id, t_table *table, char *name)
{
  philo->id = id;
  if (name != NULL)
    philo->name = strdup(name);
  philo->eaten = 0;
  philo->table = table;
  philo->need_to_eat = FALSE;
  philo->need_to_sleep = FALSE;
  philo->stick_right = FALSE;
  philo->stick_left = FALSE;
}

void			init_sticks(t_sticks *sticks, int id)
{
  sticks->id = id;
  sticks->used_by = NULL;
  sticks->used_for_think = FALSE;
}
