/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:06:36 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/27 14:16:44 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->number_of_philos)
	{
		pthread_mutex_init(&p->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&p->dead_lock, NULL);
	pthread_mutex_init(&p->meal_mutex_lock, NULL);
	pthread_mutex_init(&p->meal_lock, NULL);
	pthread_mutex_init(&p->write_lock, NULL);
	pthread_mutex_init(&p->time_lock, NULL);
}

void	init_data(t_program *p)
{
	int	i;

	i = 0;
	p->philos = malloc(sizeof(t_data) * 200);
	p->forks = malloc(sizeof(pthread_mutex_t) * 200);
	while (i < p->number_of_philos)
	{
		pthread_mutex_init(&p->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < p->number_of_philos)
	{
		p->philos[i].philos_id = i + 1;
		p->philos[i].left_fork_id = i;
		p->philos[i].right_fork_id = (i + 1) % p->number_of_philos;
		p->philos[i].philo_eat_time = 0;
		p->philos[i].last_meal_time = 0;
		p->philos[i].program = p;
		i++;
	}
}

void	init_program(t_program *p, char **argv)
{
	p->number_of_philos = new_atol(argv[1]);
	p->time_2_die = new_atol(argv[2]);
	p->time_2_eat = new_atol(argv[3]);
	p->time_2_sleep = new_atol(argv[4]);
	p->finish = 0;
	if (argv[5])
		p->number_of_meals = new_atol(argv[5]);
	else
		p->number_of_meals = -1;
}
