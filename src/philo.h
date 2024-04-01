/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:17:53 by etornay-          #+#    #+#             */
/*   Updated: 2024/04/01 17:17:10 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <stdio.h>

struct	s_program;

typedef struct s_data
{
	struct s_program	*program;
	int					philos_id;
	int					left_fork_id;
	int					right_fork_id;
	int					philo_eat_time;
	int					last_meal_time;
}	t_data;

typedef struct s_program
{
	int				number_of_philos;
	int				time_2_eat;
	int				time_2_sleep;
	int				time_2_die;
	int				number_of_meals;
	int				all_philos_eaten;
	int				start;
	int				finish;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	meal_mutex_lock;
	pthread_mutex_t	time_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	*forks;
	t_data			*philos;
}	t_program;

/* ---UTILS--- */
int				new_is_digit(char *s);
long long int	new_atol(char *s);

/* ---CHECKER--- */
int				checker(char **argv);
int				check_end(t_program *p);
int				check_death(t_program *p);

/* ---INIT_STRUCT--- */
void			init_program(t_program *p, char **argv);
void			init_data(t_program *p);
void			init_mutex(t_program *p);

/* ---TIME--- */
long			ft_get_time(void);
void			ft_usleep(t_program *p, int time);

/* ---ROUTINE--- */
void			*philo_routine(void *philo);
void			philos_eat(t_data *p);
void			only_one(t_program *p, pthread_t *t);

/* ---PHILOS_UTILS--- */
void			printf_philos(t_program *p, int id, char *s);
void			russian_roulette(t_program *p);

/* ---FREE--- */
void			free_philos(t_program *p);

#endif