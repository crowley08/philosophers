/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:22:30 by saandria          #+#    #+#             */
/*   Updated: 2024/08/22 16:27:05 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	take_right(t_philo *p)
{
	pthread_mutex_lock(&p->ta->mutex_forks[p->right]);
	p->ta->forks[p->right] = '0';
	p->stat = "has taken a fork";
	print_stat(p);
}

static void	take_left(t_philo *p)
{
	pthread_mutex_lock(&p->ta->mutex_forks[p->left]);
	p->ta->forks[p->left] = '0';
	p->stat = "has taken a fork";
	print_stat(p);
}

void	take_forks(t_philo *p)
{
	if (p->ta->p_num == 1)
	{
		take_left(p);
		ph_usleep(p->t.to_die, p->ta);
		return ;
	}
	if (p->id % 2)
	{
		take_left(p);
		take_right(p);
	}
	else
	{
		take_right(p);
		take_left(p);
	}
}
