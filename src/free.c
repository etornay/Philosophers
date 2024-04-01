/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:53:13 by etornay-          #+#    #+#             */
/*   Updated: 2024/04/01 20:33:33 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	new_free(t_program *p, pthread_t *t)
{
	
}

void	free_philos(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->number_of_philos)
	{
		pthread_mutex_destroy(&p->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&p->dead_lock);
	pthread_mutex_destroy(&p->meal_lock);
	pthread_mutex_destroy(&p->meal_mutex_lock);
	pthread_mutex_destroy(&p->time_lock);
	pthread_mutex_destroy(&p->write_lock);
}
