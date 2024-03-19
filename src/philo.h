/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:17:53 by etornay-          #+#    #+#             */
/*   Updated: 2024/03/19 14:28:40 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>

/* typedef struct s_philo
{
	
}

typedef struct s_program
{
	
}
 */
/* ---CHECKER--- */
int				checker(char **argv);
int				new_is_digit(char *s);
long long int	new_atol(char *s);

#endif