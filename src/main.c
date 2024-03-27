/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:52 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/27 19:28:15 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_3(t_program *p, pthread_t	*thread)
{
	int	i;

	i = 0;
	russian_roulette(p);
	while (i < p->number_of_philos)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	free_philos(p);
	return (EXIT_SUCCESS);
}

int	main_2(t_program *p)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * p->number_of_philos);
	pthread_mutex_lock(&p->time_lock);
	p->start = ft_get_time();
	pthread_mutex_unlock(&p->time_lock);
	if (p->number_of_philos == 1)
	{
		only_one(p, thread);
		return (EXIT_SUCCESS);
	}
	while (i < p->number_of_philos && p->number_of_philos > 1)
	{
		if (pthread_create(&thread[i], NULL, &philo_routine, &p->philos[i]))
			return (EXIT_FAILURE);
		pthread_mutex_lock(&p->time_lock);
		p->philos[i].last_meal_time = ft_get_time();
		pthread_mutex_unlock(&p->time_lock);
		i++;
	}
	if (main_3(p, thread) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_program	p;

	if (argc == 5 || argc == 6)
	{
		if (checker(argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_program(&p, argv);
		init_data(&p);
		init_mutex(&p);
		if (main_2(&p) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	printf("Error\nInvalid arguments\n");
	return (EXIT_FAILURE);
}
