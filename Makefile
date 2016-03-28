##
## Makefile for Makefile in /home/abgral_f/dev/philosophe
## 
## Made by abgral_f
## Login   <abgral_f@epitech.net>
## 
## Started on  Tue Mar 11 21:45:58 2014 abgral_f
## Last update Wed Mar 19 23:50:48 2014 abgral_f
##

CC      = gcc

RM      = rm -f

NAME    = philo

PATH1   = include/

PATH2   = src/

SRCS    = $(PATH2)main.c                                \
	  $(PATH2)error.c				\
	  $(PATH2)run_philosophe.c			\
	  $(PATH2)init.c				\
	  $(PATH2)get_param.c				\
	  $(PATH2)default_philo.c			\
	  $(PATH2)philo_bsc.c				\
	  $(PATH2)meditate.c				\
	  $(PATH2)sleep.c				\
	  $(PATH2)eat.c					\
	  $(PATH2)select_stick.c			\
	  $(PATH2)start_dinner.c			\

OBJS    = $(SRCS:.c=.o)

CFLAGS  = -W -Wall -Werror -Wextra -Wshadow -I$(PATH1)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lpthread

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
