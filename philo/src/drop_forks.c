/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:33:29 by saandria          #+#    #+#             */
/*   Updated: 2024/08/30 17:39:26 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	release_left(t_philo *p)
{
	pthread_mutex_unlock(&p->ta->mutex_forks[p->left]);
	pthread_mutex_lock(&p->ta->mutex);
	p->ta->forks[p->left] = '1';
	pthread_mutex_unlock(&p->ta->mutex);
}

static void	release_right(t_philo *p)
{
	pthread_mutex_unlock(&p->ta->mutex_forks[p->right]);
	pthread_mutex_lock(&p->ta->mutex);
	p->ta->forks[p->right] = '1';
	pthread_mutex_unlock(&p->ta->mutex);
}

void	release_forks(t_philo *p)
{
	if (p->ta->p_num == 1)
	{
		release_left(p);
		return ;
	}
	if (p->id % 2)
	{
		release_left(p);
		release_right(p);
	}
	else
	{
		release_right(p);
		release_left(p);
	}
}
