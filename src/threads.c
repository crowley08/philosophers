/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/08/06 15:26:30 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_time(t_philo *p, char *av[])
{
	p->t.to_die = ft_atol(av[2]);
	p->t.to_eat = ft_atol(av[3]);
	p->t.to_sleep = ft_atol(av[4]);
	p->eat = ft_atoi(av[5]);
}

void	ph_threads(t_table *table, char *av[])
{
	pthread_mutex_init(&table->mutex, NULL);
	init_table(table);
	init_forks(table);
	init_threads(table, av);
	join_threads(table);
	destroy_mutex(table);
	pthread_mutex_destroy(&table->mutex);
	free(table->p);
	free(table->forks);
	pthread_exit(NULL);
}
