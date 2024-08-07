/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/08/07 12:19:07 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;
	t_table	*table;

	tid = (t_philo *)p;
	table = tid->ta;
	if (tid->id % 2 == 0)
		usleep(1000);
	while (no_one_died(table))
	{
		ph_think(tid);
		take_forks(p);
		ph_eat(tid);
		release_forks(p);
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
	usleep(p->t.to_sleep * 1000);
}

void	ph_eat(t_philo *p)
{
	pthread_mutex_lock(&p->ta->dead);
	p->t.last_eat = get_time();
	pthread_mutex_unlock(&p->ta->dead);
	p->stat = "\033[1;95mis eating";
	print_stat(p);
	p->eaten++;
	usleep(p->t.to_eat * 1000);
}
void	ph_died(t_philo *p)
{

	p->stat = "\033[1;91mdied";
	printf("\033[1;3m%lld  %d %s\n\033[0m", p->ts, p->id, p->stat);
	clean_threads(p->ta);
//	exit(1);
}
/*
*/
