/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:00:56 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 13:05:27 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_table(t_table *table, char *av[])
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->mutex);
	while (i < table->p_num)
	{
		table->p[i].id = i + 1;
		table->p[i].left = i;
		table->p[i].right = (i + 1) % table->p_num;
		table->p[i].eaten = 0;
		table->start = get_time();
		table->p[i].ta = table;
		pthread_mutex_lock(&table->dead);
		if (av[5])
			table->p[i].eat = ph_atoi(av[5]);
		else
			table->p[i].eat = -1;
		pthread_mutex_unlock(&table->dead);
		i++;
	}
	pthread_mutex_unlock(&table->mutex);
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	*init_threads(t_table *table, char *av[])
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		init_time(&table->p[i], av);
		i++;
	}
	if (pthread_create(&table->monitor, NULL, ph_monitor, table))
		return (clear(table, "Can't create monitor"));
	i = 0;
	while (i < table->p_num)
	{
		if (pthread_create(&table->p[i].threads, NULL, to_do, &table->p[i]))
			return (clear(table, "can't create threads"));
		i++;
	}
	return (NULL);
}

void	init_time(t_philo *p, char *av[])
{
	p->t.to_die = ph_atol(av[2]);
	p->t.to_eat = ph_atol(av[3]);
	p->t.to_sleep = ph_atol(av[4]);
	pthread_mutex_lock(&p->ta->mutex);
	p->t.last_eat = p->ta->start;
	pthread_mutex_unlock(&p->ta->mutex);
}
