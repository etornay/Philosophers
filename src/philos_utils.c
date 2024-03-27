/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:40:05 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/27 19:15:23 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_program *p)
{
	int	death;
	int	diff;

	death = p->time_2_die;
	pthread_mutex_lock(&p->time_lock);
	diff = ft_get_time() - p->philos->last_meal_time;
	pthread_mutex_unlock(&p->time_lock);
	if (diff >= death)
	{
		printf_philos(p, p->philos->philos_id, "died");
		pthread_mutex_lock(&p->dead_lock);
		p->finish = 1;
		pthread_mutex_unlock(&p->dead_lock);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	russian_roulette(t_program *p)
{
	while (33)
	{
		check_death(p);
		if (check_end(p) == EXIT_FAILURE)
			break ;
	}
}

void	printf_philos(t_program *p, int id, char *s)
{
	int	time;

	pthread_mutex_lock(&p->time_lock);
	time = ft_get_time() - p->start;
	pthread_mutex_unlock(&p->time_lock);
	pthread_mutex_lock(&p->write_lock);
	pthread_mutex_lock(&p->dead_lock);
	if (p->finish != 1)
	{
		pthread_mutex_unlock(&p->dead_lock);
		printf("%i %d %s\n", time, id, s);
	}
	else
		pthread_mutex_unlock(&p->dead_lock);
	pthread_mutex_unlock(&p->write_lock);
}
