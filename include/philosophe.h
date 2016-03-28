/*
** philosophe.h for philosophe.h in /home/abgral_f/dev/philosophe
**
** Made by abgral_f
** Login   <abgral_f@epitech.net>
**
** Started on  Tue Mar 11 19:23:11 2014 abgral_f
** Last update Fri Mar 21 16:39:07 2014 abgral_f
*/

#ifndef			PHILOSOPHE_H_
# define		PHILOSOPHE_H_

#include		<pthread.h>
#include		<stdio.h>

/* DEFINES */

# define NB_RESOURCES	40
# define NB_PHIL        7
# define NB_STICKS	NB_PHIL
# define THINK_TIME     1
# define EAT_TIME	2
# define SLEEP_TIME	3
# define RESOURCES_STR	"Number of resources :"
# define MEDITATING	"Philosophe %s is meditating\n"
# define SLEEPING	"Philosophe %s is sleeping\n"
# define RICE		"Rice => %d\n"
# define EATING		"Philosophe %s is eating\n"
# define FOPEN_MODE	"r"

/* ERROR */

# define EMPTY_CONF	"Philosophe : Conf file is empty.\n"
# define MALLOC_ERR	"Philosophe : Error on malloc.\n"
# define OPEN_ERR	"Philosophe : Error on open.\n"
# define CONF_ERROR	"Philosophe : Error in the conf file.\n"
# define RESOURCES_ERR	"Philosophe : Resources must have a positif value.\n"
# define PHILO_ERR	"Philosophe : Philosophes must be 2 at least.\n"

/* STUCTURES */

typedef enum
  {
    FALSE,
    TRUE
  }			bool;

typedef struct s_table t_table;

typedef struct		s_philo
{
  char			*name;
  bool			need_to_eat;
  bool			need_to_sleep;
  int			id;
  int			eaten;
  bool			stick_left;
  bool			stick_right;
  t_table		*table;
}			t_philo;

typedef struct		s_sticks
{
  int			id;
  t_philo		*used_by;
  bool			used_for_think;
}			t_sticks;

typedef struct		s_table
{
  t_philo		*philo;
  t_sticks		*sticks;
  pthread_mutex_t	*mut_sticks;
  int			resources;
  pthread_mutex_t	mut_resources;
  int			resources_ref;
  int			nb_philo;
}			t_table;

/* PROTOTYPES */

int			main(int, char **);
int			error(char *);
int			run_philosophe(t_table *);
void                    init_philo(t_philo *, int, t_table *, char *);
void			init_sticks(t_sticks *, int);
int                     default_philo(t_table *);
FILE                    *open_file(char *);
int                     get_size(t_table *, FILE *);
void                    get_philo_name(t_table *, FILE *);
int                     get_philosophes(t_table *, FILE *);
int                     get_param(int, char **, t_table *);
int                     philo_bsc(int, char **);
void                    display_philo(t_philo *);
int                     init_table(t_table *, int);
void                    *start_dinner(void *);
void                    available_actions(t_philo *);
void                    dinner_constraints(t_philo *);
void                    eat_mutex(t_philo *, int);
void                    eat(t_philo *);
void                    rest(t_philo *);
int                     get_right_stick(t_philo *);
int                     get_left_stick(t_philo *);
int                     select_case(t_philo *);
void                    meditate(t_philo *);
void                    meditate_case(t_philo *, int);
void                    put_stick_down(t_philo *, int);

#endif
