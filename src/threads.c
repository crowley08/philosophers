/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/07/30 17:22:16 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_table		table;
	int			t_num;
	int			i;

	if (ac > 1)
		t_num = ft_atoi(av[1]);
	else
		return (0);
	table.p = malloc(sizeof(t_philo) * t_num);
	i = 0;
	while (i < t_num)
	{
		pthread_mutex_init(&table.p[i].mutex, NULL);
		table.p[i].id = i + 1;
		i++;
	}
	i = 0;
	while (i < t_num)
	{
		pthread_create(&table.p[i].threads, NULL, to_do, &table.p[i]);
		table.p[i].time = ft_atol(av[2]);
		i++;
	}
	i = 0;
	while (i < t_num)
	{
		pthread_join(table.p[i].threads, NULL);
		pthread_mutex_destroy(&table.p[i].mutex);
		i++;
	}
	free(table.p);
	pthread_exit(NULL);
}
