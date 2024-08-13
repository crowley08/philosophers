/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:16:34 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 13:04:52 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_stat(t_philo *p)
{
	pthread_mutex_lock(&p->ta->mutex);
	p->ts = get_time() - p->ta->start;
	pthread_mutex_unlock(&p->ta->mutex);
	pthread_mutex_lock(&p->ta->dead);
	if (!p->ta->one_is_dead)
		printf("\033[1;3m%lld  %d %s\n\033[0m", p->ts, p->id, p->stat);
	pthread_mutex_unlock(&p->ta->dead);
}

void	take_forks(t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		print_stat(p);
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		print_stat(p);
	}
	else
	{
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		print_stat(p);
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		print_stat(p);
	}
}

void	release_forks(t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_unlock(&p->ta->forks[p->left]);
		pthread_mutex_unlock(&p->ta->forks[p->right]);
	}
	else
	{
		pthread_mutex_unlock(&p->ta->forks[p->right]);
		pthread_mutex_unlock(&p->ta->forks[p->left]);
	}
}

void	*ph_monitor(void *t)
{
	t_table		*table;
	int			i;

	table = (t_table *)t;
	while (table->one_is_dead == 0 && table->everyone_ate == 0)
	{
		i = 0;
		if (check_ate(table))
			break ;
		while (i < table->p_num)
		{
			if (check_death(table, i))
				break ;
			i++;
		}
	}
	return (NULL);
}
