/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/08/03 05:49:05 by saandria         ###   ########.fr       */
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
		table->p[i].ta = table;
		table->p[i].eaten = 0;
		table->start = get_time();
		i++;
	}
}

void	init_time(t_philo *p, char *av[])
{
	p->t.to_die = ft_atol(av[2]);
	p->t.to_eat = ft_atol(av[3]);
	p->t.to_sleep = ft_atol(av[4]);
	p->ta->eat = ft_atoi(av[5]);
}

void	ph_threads(t_table *table, char *av[])
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_init(&table->p[i].mutex, NULL);
		pthread_mutex_init(&table->forks[i], NULL);
		init_table(table);
		pthread_create(&table->p[i].threads, NULL, to_do, &table->p[i]);
		init_time(&table->p[i], av);
		i++;
	}
	i = 0;
	while (i < table->p_num)
	{
		pthread_join(table->p[i].threads, NULL);
		pthread_mutex_destroy(&table->p[i].mutex);
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	free(table->p);
	free(table->forks);
	pthread_exit(NULL);
}

int	main(int ac, char *av[])
{
	t_table		table;

	if (ac == 6)
	{
		table.p_num = ft_atoi(av[1]);
		table.p = malloc(sizeof(t_philo) * table.p_num);
		table.ts = 0;
		table.forks = malloc(sizeof(pthread_mutex_t) * table.p_num);
		ph_threads(&table, av);
	}
	return (0);
}
