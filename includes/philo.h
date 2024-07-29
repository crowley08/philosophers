/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:31 by saandria          #+#    #+#             */
/*   Updated: 2024/07/29 16:27:07 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef	struct s_philo
{
	pthread_t	*threads;
	char		*status;
	int			id;
	int			forks;
}				t_philo;

/*
typedef	struct s_table
{
	t_philo	*ph;
}			t_table;
*/

void	*to_do(void *p);
void	*ph_think(t_philo *p);
void	*ph_eat(t_philo *p);
void	*ph_sleep(t_philo *p);
void	*ph_died(t_philo *p);

#endif