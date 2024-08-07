/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:44:07 by saandria          #+#    #+#             */
/*   Updated: 2024/08/07 12:07:32 by saandria         ###   ########.fr       */
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
		ph_died(&table->p[i]);
		pthread_mutex_unlock(&table->dead);
	//	table->p[i].stat = "\033[1;91mdied";
	//	print_stat(&table->p[i]);
		return (1);
	}
	return (0);
}

void	*death_thread(void *t)
{
	t_table		*table;
	int			i;

	table = (t_table *)t;
	while (table->one_is_dead == 0)
	{
		i = 0;
		while (i < table->p_num)
		{
			if (check_death(table, i))
				break ;
			i++;
		}
	}
	return (NULL);
}