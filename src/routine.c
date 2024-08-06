/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/08/06 13:12:42 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;

	tid = (t_philo *)p;
	if (tid->id % 2 == 0)
		usleep(1000);
	while (tid->eaten != tid->eat)
	{
		ph_think(tid);
		ph_eat(tid);
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
	take_forks(p);
	p->stat = "\033[1;95mis eating";
	print_stat(p);
	p->eaten++;
	usleep(p->t.to_eat * 1000);
	release_forks(p);
}

void	ph_died(t_philo *p)
{
	p->stat = "\033[1;91mdied";
	print_stat(p);
}
