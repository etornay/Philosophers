/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:33:19 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/18 18:41:12 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	checker2(char **argv)
{
	
}

int	checker(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (new_is_digit(argv[i]) == EXIT_FAILURE)
		{
			printf("Error\nNot a digit argument\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
	while (argv[i])
	{
		if (atol(argv[i]) > 2147483647)
		{
			printf("Error\nBigger number\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (checker2(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
