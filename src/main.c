/*
** philosophe.c for philosophe.c in /home/abgral_f/dev/philosophe
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Mar 11 19:21:45 2014 abgral_f
** Last update Sat Mar 15 16:21:18 2014 abgral_f
*/

#include		<stdlib.h>
#include		<philosophe.h>

int			main(int argc, char **argv)
{
  if (philo_bsc(argc, argv) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
