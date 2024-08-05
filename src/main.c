/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:08:58 by saandria          #+#    #+#             */
/*   Updated: 2024/08/05 16:38:56 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_table		table;

	if (ac == 6)
	{
		table.p_num = ft_atoi(av[1]);
		table.p = malloc(sizeof(t_philo) * table.p_num);
	//	table.ts = 0;
		table.forks = malloc(sizeof(pthread_mutex_t) * table.p_num);
		ph_threads(&table, av);
	}
	return (0);
}
