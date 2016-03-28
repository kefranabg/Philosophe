/*
** error.c for error.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Mar 11 21:47:46 2014 abgral_f
** Last update Tue Mar 11 21:49:13 2014 abgral_f
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		"philosophe.h"

int			error(char *str)
{
  fprintf(stderr, "%s", str);
  return (EXIT_FAILURE);
}
