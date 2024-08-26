/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:03:53 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 15:29:00 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_ate(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	table->everyone_ate = 1;
	pthread_mutex_unlock(&table->dead);
}

int	someone_didn_t_eat_yet(t_table *table)
{
	pthread_mutex_lock(&table->dead);
	if (table->everyone_ate == 1)
		return (pthread_mutex_unlock(&table->dead), 0);
	pthread_mutex_unlock(&table->dead);
	return (1);
}

int	check_ate(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_lock(&table->dead);
		if (table->p[i].eat == -1)
			return (pthread_mutex_unlock(&table->dead), 0);
		if (table->p[i].eat > table->p[i].eaten)
			return (pthread_mutex_unlock(&table->dead), 0);
		pthread_mutex_unlock(&table->dead);
		i++;
	}
	ph_ate(table);
	return (1);
}
