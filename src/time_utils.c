/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:29:23 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/25 17:43:22 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(t_program *p, int time)
{
	long	total_time;

	total_time = ft_get_time() + time;
	while (ft_get_time() < total_time)
	{
		pthread_mutex_lock(&(p->finish));
		if (p->finish != 1)
		{
			pthread_mutex_unlock(&(p->finish));
			usleep(10);
		}
		else
		{
			pthread_mutex_unlock(&(p->finish));
			break ;
		}
	}
}

long	ft_difference_time(t_program *p)
{
	return (ft_get_time() - p->start);
}

long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		printf("Error\nFailed in the function get time of day\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
