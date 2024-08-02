/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/08/01 13:51:52 by saandria         ###   ########.fr       */
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
		table->p[i].id = i + 1;
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
		i++;
	}
	free(table->p);
	pthread_exit(NULL);
}

int	main(int ac, char *av[])
{
	t_table		table;

	if (ac == 6)
	{
		table.p_num = ft_atoi(av[1]);
		table.p = malloc(sizeof(t_philo) * table.p_num);
		ph_threads(&table, av);
	}
	return (0);
}
