/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/08/03 01:14:36 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_threads(t_table *table, char *av[])
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_init(&table->p[i].mutex, NULL);
		pthread_mutex_init(&table->forks[i], NULL);
		table->p[i].id = i + 1;
		table->p[i].left = i;
		table->p[i].right = (i + 1) % table->p_num;
		table->p[i].ta = table;
		table->p[i].eaten = 0;
		i++;
	}
	i = 0;
	while (i < table->p_num)
	{
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
		table.forks = malloc(sizeof(pthread_mutex_t) * table.p_num);
		ph_threads(&table, av);
	}
	return (0);
}
