/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:52 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/21 18:24:28 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_2(t_program *p)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	thread = malloc(sizeof(pthread_t) * p->number_of_philos);
	while (i < p->number_of_philos && p->number_of_philos > 1)
	{
		i++;
	}
}

int	main(int argc, char **argv, t_program *p, t_data *d)
{
	if (argc == 5 || argc == 6)
	{
		if (checker(argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_program(p, argv);
		init_data(p, d);
		init_mutex(p);
		if (main_2(p) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
	{
		printf("Error\nInvalid arguments\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
