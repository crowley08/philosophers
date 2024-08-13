/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:16:29 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 10:15:01 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_usleep(long ts)
{
	long	start;

	start = get_time();
	while (get_time() - start < ts)
		usleep(1);
}

void	*join_threads(t_table *table)
{
	int	i;

	i = 0;
	if (pthread_join(table->death_threads, NULL))
		return (clear(table, "can't join death_threads"));
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
