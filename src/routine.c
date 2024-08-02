/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/08/03 00:07:15 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;

	tid = (t_philo *)p;
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
	p->stat = "\033[1;93mthinking...";
	printf("\033[1;3m%d is %s\n\033[0m", p->id, p->stat);
}

void	ph_sleep(t_philo *p)
{
	p->stat = "\033[1;92msleeping...";
	printf("\033[1;3m%d is %s\n\033[0m", p->id, p->stat);
	usleep(p->t.to_sleep * 1000);
}

void	ph_eat(t_philo *p)
{
	pthread_mutex_lock(&p->mutex);
	p->stat = "\033[1;95meating...";
	printf("\033[1;3m%d is %s\n\033[0m", p->id, p->stat);
	usleep(p->t.to_eat * 1000);
	pthread_mutex_unlock(&p->mutex);
}

void	ph_died(t_philo *p)
{
	p->stat = "\033[1;91mdied...";
	printf("\033[1;3m%d is %s\n\033[0m", p->id, p->stat);
}
