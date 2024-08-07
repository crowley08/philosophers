/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:16:29 by saandria          #+#    #+#             */
/*   Updated: 2024/08/07 12:45:25 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	init_table(t_table *table)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&table->mutex);
	while (i < table->p_num)
	{
		table->p[i].id = i + 1;
		table->p[i].left = i;
		table->p[i].right = (i + 1) % table->p_num;
		table->p[i].eaten = 0;
		table->start = get_time();
		table->p[i].ta = table;
		i++;
	}
	pthread_mutex_unlock(&table->mutex);
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
}

void	init_threads(t_table *table, char *av[])
{
	int	i;

	i = 0;
	while (i < table->p_num)
	{
		init_time(&table->p[i], av);
		i++;	
	}
	pthread_create(&table->death_threads, NULL, death_thread, table);
	i = 0;
	while (i < table->p_num)
	{
		pthread_create(&table->p[i].threads, NULL, to_do, &table->p[i]);
		i++;
	}
}

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
	//	if (table->leftlock == 1 || table->rightlock == 1)
		pthread_mutex_unlock(&table->forks[i]);
		i++;
	}
}

void	clean_threads(t_table *table)
{
//	unlock_mutex(table);
	destroy_mutex(table);
	pthread_mutex_unlock(&table->mutex);
	pthread_mutex_destroy(&table->mutex);
	pthread_mutex_unlock(&table->dead);
	pthread_mutex_destroy(&table->dead);
	free(table->p);
	free(table->forks);
}
