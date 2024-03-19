/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:19 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/19 14:28:58 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	checker3(char **argv)
{
	if (new_atol(argv[5]) < 0)
	{
		printf("Error\nIncorrect number of meals\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	checker2(char **argv)
{
	if (new_atol(argv[1]) < 1 || new_atol(argv[1]) > 200)
	{
		printf("Error\nIncorrect number of philosophers\n");
		return (EXIT_FAILURE);
	}
	if (new_atol(argv[2]) <= 0)
	{
		printf("Error\nIncorrect time to die\n");
		return (EXIT_FAILURE);
	}
	if (new_atol(argv[3]) <= 0)
	{
		printf("Error\nIncorrect time to eat\n");
		return (EXIT_FAILURE);
	}
	if (new_atol(argv[4]) <= 0)
	{
		printf("Error\nIncorrect time to sleep\n");
		return (EXIT_FAILURE);
	}
	if (checker3(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	checker(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (new_is_digit(argv[i]) == EXIT_FAILURE)
		{
			printf("Error\nNot a digit argument\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		if (atol(argv[i]) > 2147483647)
		{
			printf("Error\nNot valid number\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (checker2(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
