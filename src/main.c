/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:13:52 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/20 15:43:00 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv, t_program *p)
{
	if (argc == 5 || argc == 6)
	{
		if (checker(argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		init_program(p, argv);
		init_data(p);
	}
	else
	{
		printf("Error\nInvalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
