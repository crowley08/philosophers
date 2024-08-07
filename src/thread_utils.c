/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:16:29 by saandria          #+#    #+#             */
/*   Updated: 2024/08/07 14:02:21 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	pthread_join(table->death_threads, NULL);
	while (i < table->p_num)
	{
		pthread_join(table->p[i].threads, NULL);
		i++;
	}
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

void	unlock_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_unlock(&table->forks[i]);
		i++;
	}
}

void	clean_threads(t_table *table)
{
	destroy_mutex(table);
	pthread_mutex_destroy(&table->dead);
	pthread_mutex_destroy(&table->mutex);
	free(table->p);
	free(table->forks);
}
