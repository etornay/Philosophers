/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:01:35 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/26 19:19:53 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_philos(t_program *p, int id, char *s)
{
	int	time;

	pthread_mutex_lock(&p->time_lock);
	time = ft_get_time() - p->start;
	pthread_mutex_unlock(&p->time_lock);
	pthread_mutex_lock(&p->dead_lock);
	if (p->finish != 1)
	{
		pthread_mutex_unlock(&p->dead_lock);
		pthread_mutex_lock(&p->write_lock);
		printf("%i %d %s\n", time, id, s);
		pthread_mutex_unlock(&p->write_lock);
	}
}

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
