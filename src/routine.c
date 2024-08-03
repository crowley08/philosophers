/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/08/03 04:38:44 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;

	tid = (t_philo *)p;
	if (tid->id % 2 == 0)
		usleep(1000);
	while (tid->eaten != tid->ta->eat)
	{
		tid->ta->ts++;
		take_forks(tid);
		ph_eat(tid);
		release_forks(tid);
		ph_sleep(tid);
		ph_think(tid);
	}
	return (NULL);
}

void	ph_think(t_philo *p)
{
	p->stat = "\033[1;93m is thinking...";
	printf("\033[1;3m%lld  %d %s\n\033[0m", p->ta->ts * 1000, p->id, p->stat);
}

void	ph_sleep(t_philo *p)
{
	p->stat = "\033[1;92mis sleeping...";
	printf("\033[1;3m%lld  %d %s\n\033[0m", p->ta->ts * 1000, p->id, p->stat);
	usleep(p->t.to_sleep * 1000);
}

void	ph_eat(t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	p->stat = "\033[1;95mis eating...";
	printf("\033[1;3m%lld  %d %s\n\033[0m", p->ta->ts * 1000, p->id, p->stat);
	p->eaten++;
	printf("%lld  %d ate %d times\n", p->ta->ts * 1000, p->id, p->eaten);
	usleep(p->t.to_eat * 1000);
	pthread_mutex_unlock(&p->mutex);
}

void	ph_died(t_philo *p)
{
	p->ta->ts++;
	p->stat = "\033[1;91mis died...";
	printf("\033[1;3m%lld  %d %s\n\033[0m", p->ta->ts * 1000, p->id, p->stat);
}
