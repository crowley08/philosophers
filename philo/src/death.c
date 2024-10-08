/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:44:07 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 15:29:03 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	is_dead(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	table->one_is_dead = 1;
	pthread_mutex_unlock(&table->dead);
}

int	no_one_died(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	if (table->one_is_dead == 1)
		return (pthread_mutex_unlock(&table->dead), 0);
	pthread_mutex_unlock(&table->dead);
	return (1);
}

int	check_death(t_table *table, int i)
{
	long long	time;
	long long	time_diff;

	time = get_time();
	pthread_mutex_lock(&table->dead);
	time_diff = time - table->p[i].t.last_eat;
	pthread_mutex_unlock(&table->dead);
	if (time_diff > table->p[i].t.to_die)
	{
		is_dead(table);
		pthread_mutex_lock(&table->dead);
		printf("\033[1;3m%lld  %d %s\n\033[0m", time - table->start,
			table->p[i].id, "\033[1;91mdied");
		pthread_mutex_unlock(&table->dead);
		return (1);
	}
	return (0);
}
