/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/09/02 07:49:11 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ph_one(t_philo *p)
{
	ph_think(p);
	take_forks(p);
	release_forks(p);
	usleep(p->t.to_die);
}

void	*to_do(void *p)
{
	t_philo	*tid;
	t_table	*table;

	tid = (t_philo *)p;
	table = tid->ta;
	if (tid->id % 2 == 0)
		usleep(1000);
	if (table->p_num == 1)
	{
		ph_one(tid);
		return (NULL);
	}
	while (no_one_died(table) && someone_didn_t_eat_yet(table))
	{
		ph_think(tid);
		take_forks(tid);
		ph_eat(tid);
		release_forks(tid);
		ph_sleep(tid);
	}
	return (NULL);
}

void	ph_think(t_philo *p)
{
	p->stat = "\033[1;93mis thinking";
	print_stat(p);
}

void	ph_sleep(t_philo *p)
{
	p->stat = "\033[1;92mis sleeping";
	print_stat(p);
	ph_usleep(p->t.to_sleep, p->ta);
}

void	ph_eat(t_philo *p)
{
	pthread_mutex_lock(&p->ta->dead);
	p->t.last_eat = get_time();
	pthread_mutex_unlock(&p->ta->dead);
	p->stat = "\033[1;95mis eating";
	print_stat(p);
	pthread_mutex_lock(&p->ta->dead);
	p->eaten++;
	pthread_mutex_unlock(&p->ta->dead);
	ph_usleep(p->t.to_eat, p->ta);
}
