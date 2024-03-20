/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:01:35 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/19 15:32:59 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	new_is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (EXIT_FAILURE);
		else
			s++;
	}
	return (EXIT_SUCCESS);
}

long long int	new_atol(char *s)
{
	long long int	num;
	int				sign;

	sign = 1;
	num = 0;
	while ((*s >= 9 && *s <= 13) || (*s == ' '))
		(*s)++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		(*s)++;
	}
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - 48);
		s++;
	}
	return (sign * num);
}
