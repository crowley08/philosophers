/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/08/05 17:10:37 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;

	tid = (t_philo *)p;
	if (tid->id % 2 == 0)
		usleep(1000);
	while (1)
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
	p->stat = "is thinking";
	pthread_mutex_lock(&p->ta->protec);
	p->ts = get_time() - p->ta->start;
	printf("%lld  %d %s\n", p->ts, p->id, p->stat);
	pthread_mutex_unlock(&p->ta->protec);
}

void	ph_sleep(t_philo *p)
{
	p->stat = "is sleeping";
	pthread_mutex_lock(&p->ta->protec);
	p->ts = get_time() - p->ta->start;
	printf("%lld  %d %s\n", p->ts, p->id, p->stat);
	usleep(p->ta->t.to_sleep * 1000);
	pthread_mutex_unlock(&p->ta->protec);
}

void	ph_eat(t_philo *p)
{
	//pthread_mutex_lock(&p->mutex);
	p->stat = "is eating";
	pthread_mutex_lock(&p->ta->protec);
	p->ts = get_time() - p->ta->start;
	printf("%lld  %d %s\n", p->ts, p->id, p->stat);
	p->eaten++;
	//printf("%lld  %d ate %d times\n", p->ts, p->id, p->eaten);
	usleep(p->ta->t.to_eat * 1000);
	pthread_mutex_unlock(&p->ta->protec);
	//pthread_mutex_unlock(&p->mutex);
}

void	ph_died(t_philo *p)
{
	p->stat = "\033[1;91mdied";
	pthread_mutex_lock(&p->ta->protec);
	p->ts = get_time() - p->ta->start;
	printf("%lld  %d %s\n", p->ts, p->id, p->stat);
	pthread_mutex_unlock(&p->ta->protec);
}
