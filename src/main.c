/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:52 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/25 17:44:05 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_2(t_program *p)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * p->number_of_philos);
	pthread_mutex_lock(&p->time_lock);
	p->start = ft_get_time;
	while (i < p->number_of_philos && p->number_of_philos > 1)
	{
		i++;
	}
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
