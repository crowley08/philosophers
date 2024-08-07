/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/08/07 12:22:57 by saandria         ###   ########.fr       */
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
	pthread_mutex_lock(&p->ta->mutex);
	p->t.last_eat = p->ta->start;
	pthread_mutex_unlock(&p->ta->mutex);
}

void	ph_threads(t_table *table, char *av[])
{
	pthread_mutex_init(&table->mutex, NULL);
	pthread_mutex_init(&table->dead, NULL);
	init_table(table);
	init_forks(table);
	init_threads(table, av);
	join_threads(table);
	clean_threads(table);
	pthread_exit(NULL);
	/*
	destroy_mutex(table);
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_destroy(&table->dead);
	free(table->p);
	free(table->forks);
	pthread_exit(NULL);
	*/
}
