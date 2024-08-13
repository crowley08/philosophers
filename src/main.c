/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:08:58 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 11:51:32 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_table		table;

	if (ac >= 5 && ac < 7)
	{
		table.p_num = ph_atoi(av[1]);
		table.p = malloc(sizeof(t_philo) * table.p_num);
		table.forks = malloc(sizeof(pthread_mutex_t) * table.p_num);
		table.everyone_ate = 0;
		if (!table.p || !table.forks)
		{
			free_all(&table);
			return (0);
		}
		table.one_is_dead = 0;
		ph_threads(&table, av);
	}
	else
		printf("should be like ./philo 4 300 200 100 [4]\n");
	return (0);
}
