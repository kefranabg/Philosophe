/*
** philo_bsc.c for philo_bsc.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Sat Mar 15 12:47:23 2014 abgral_f
** Last update Sat Mar 15 20:02:19 2014 abgral_f
*/

#include		<stdlib.h>
#include		"philosophe.h"

int			philo_bsc(int argc, char **argv)
{
  t_table		table;

  if (get_param(argc, argv, &table) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (run_philosophe(&table) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  free(table.mut_sticks);
  free(table.philo);
  free(table.sticks);
  return (EXIT_SUCCESS);
}
