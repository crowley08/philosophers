/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:11:41 by saandria          #+#    #+#             */
/*   Updated: 2024/07/29 16:27:01 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *p)
{
	t_philo	*tid;
	pthread_mutex_t	mutex;

	tid = (t_philo *)p;
	printf("\033[1;12m%d is \033[0m", tid->id);
	ph_sleep(tid);
	printf("%s\n\033[0m", tid->status);
	sleep(3);
	return (NULL);
}

void	*ph_think(t_philo *p)
{
	p->status = "\033[1;93m\033[1;6mthinking...";
}

void	*ph_sleep(t_philo *p)
{
	p->status = "\033[1;92m\033[1;6msleeping...";
}

void	*ph_eat(t_philo *p)
{
	p->status = "\033[1;95m\033[1;6meating...";
}

void	*ph_died(t_philo *p)
{
	p->status = "\033[1;91m\033[1;6mdied...";
}