/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/08/01 13:55:04 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;

	tid = (t_philo *)p;
	while (1)
	{
		pthread_mutex_lock(&tid->mutex);
		ph_sleep(tid);
		printf("\033[1;3m%d is %s\n\033[0m", tid->id, tid->stat);
		pthread_mutex_unlock(&tid->mutex);
	}
	return (NULL);
}

void	ph_think(t_philo *p)
{
	p->stat = "\033[1;93m\033[1;6mthinking...";
	usleep(p->t.to_die);
}

void	ph_sleep(t_philo *p)
{
	p->stat = "\033[1;92m\033[1;6msleeping...";
	usleep(p->t.to_sleep);
}

void	ph_eat(t_philo *p)
{
	p->stat = "\033[1;95m\033[1;6meating...";
	usleep(p->t.to_eat);
}

void	ph_died(t_philo *p)
{
	p->stat = "\033[1;91m\033[1;6mdied...";
}
