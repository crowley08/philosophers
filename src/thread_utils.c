/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:16:29 by saandria          #+#    #+#             */
/*   Updated: 2024/08/18 14:23:10 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_usleep(long ts, t_table *table)
{
	long	start;

	start = get_time();
	while (get_time() - start < ts)
	{
		if (no_one_died(table) == 0 || someone_didn_t_eat_yet(table) == 0)
			break ;
		usleep(1);
	}
}

void	*join_threads(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_join(table->monitor, NULL))
		return (clear(table, "can't join monitor"));
	while (i < table->p_num)
	{
		if (pthread_join(table->p[i].threads, NULL))
			return (clear(table, "Can't join threads"));
		i++;
	}
	return (NULL);
}

void	destroy_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}
