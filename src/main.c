/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:08:58 by saandria          #+#    #+#             */
/*   Updated: 2024/08/09 09:36:26 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_table		table;

	if (ac >= 5)
	{
		table.p_num = ph_atoi(av[1]);
		table.p = malloc(sizeof(t_philo) * table.p_num);
		table.forks = malloc(sizeof(pthread_mutex_t) * table.p_num);
		table.one_is_dead = 0;
		ph_threads(&table, av);
	}
	return (0);
}
