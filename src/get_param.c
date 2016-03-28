/*
** get_param.c for get_param.c in /home/abgral_f/dev/philosophe/src
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Fri Mar 14 12:30:34 2014 abgral_f
** Last update Fri Mar 21 16:32:04 2014 abgral_f
*/

#include		<stdlib.h>
#include		<string.h>
#include		"philosophe.h"

FILE			*open_file(char *str)
{
  FILE			*fd;

  if ((fd = fopen(str, FOPEN_MODE)) == NULL)
    {
      error(OPEN_ERR);
      return (NULL);
    }
  return (fd);
}

int			get_size(t_table *table, FILE *fd)
{
  int                   count;
  char                  *line;
  size_t                len;

  count = 0;
  line = NULL;
  while (getline(&line, &len, fd) != -1)
    {
      line[strlen(line) - 1] = '\0';
      if (count == 0)
	{
	  if (strncmp(line, RESOURCES_STR, strlen(RESOURCES_STR)) != 0)
	    return (error(CONF_ERROR));
	  if ((table->resources = atoi(&line[strlen(RESOURCES_STR)])) < 0)
	    return (error(RESOURCES_ERR));
	}
      count++;
    }
  if (count == 0)
    return (error(EMPTY_CONF));
  if (init_table(table, count) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (count - 1 < 2)
    return (error(PHILO_ERR));
  return (EXIT_SUCCESS);
}

void			get_philo_name(t_table *table, FILE *fd)
{
  int                   count;
  char                  *line;
  size_t                len;

  fseek(fd, 0, SEEK_SET);
  count = 0;
  line = NULL;
  getline(&line, &len, fd);
  while (getline(&line, &len, fd) != -1)
    {
      line[strlen(line) - 1] = '\0';
      init_philo(&(table->philo[count]), count, table, line);
      count++;
    }
  fclose(fd);
}

int			get_philosophes(t_table *table, FILE *fd)
{
  if (get_size(table, fd) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  get_philo_name(table, fd);
  return (EXIT_SUCCESS);
}

int			get_param(int argc, char **argv, t_table *table)
{
  FILE			*fd;

  if (argc > 1)
    {
      if ((fd = open_file(argv[1])) == NULL)
	return (EXIT_FAILURE);
      if (get_philosophes(table, fd) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    {
      if (default_philo(table) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
