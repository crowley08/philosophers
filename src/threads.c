/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/08/05 17:11:28 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	init_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		table->p[i].id = i + 1;
		table->p[i].left = i;
		table->p[i].right = (i + 1) % table->p_num;
		table->p[i].eaten = 0;
		table->start = get_time();
		table->p[i].ta = table;
		i++;
	}
}

void	init_time(t_table *t, char *av[])
{
	t->t.to_die = ft_atol(av[2]);
	t->t.to_eat = ft_atol(av[3]);
	t->t.to_sleep = ft_atol(av[4]);
//	pthread_mutex_lock(&t->ta->protec);
	t->eat = ft_atoi(av[5]);
//	pthread_mutex_unlock(&p->ta->protec);
}

void	ph_threads(t_table *table, char *av[])
{
	int	i;

	i = 0;
	init_table(table);
	init_time(table, av);
	pthread_mutex_init(&table->protec, NULL);
	while (i < table->p_num)
	{
	//	pthread_mutex_init(&table->p[i].mutex, NULL);
		pthread_mutex_init(&table->forks[i], NULL);
		i++;	
	}
	i = 0;
	while (i < table->p_num)
	{
		//init_time(&table->p[i], av);
		pthread_create(&table->p[i].threads, NULL, to_do, &table->p[i]);
		i++;
	}
	i = 0;
	while (i < table->p_num)
	{
		pthread_join(table->p[i].threads, NULL);
		//pthread_mutex_destroy(&table->p[i].mutex);
		//pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	i = 0;
	while (i < table->p_num)
	{
		//pthread_join(table->p[i].threads, NULL);
	//	pthread_mutex_destroy(&table->p[i].mutex);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->protec);
	free(table->p);
	free(table->forks);
	pthread_exit(NULL);
}
