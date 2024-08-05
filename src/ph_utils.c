/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:16:34 by saandria          #+#    #+#             */
/*   Updated: 2024/08/05 17:00:06 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	eaten_n_times(t_philo *p)
{
	pthread_mutex_lock(&p->ta->protec);
	if (p->eaten != p->ta->eat)
		return (pthread_mutex_unlock(&p->ta->protec), 1);
	pthread_mutex_unlock(&p->ta->protec);
	return (0);
}

void	take_forks(t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		printf("%lld  %d %s\n", p->ts, p->id, p->stat);
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		printf("%lld  %d %s\n", p->ts, p->id, p->stat);
	}
	else
	{
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		printf("%lld  %d %s\n", p->ts, p->id, p->stat);
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		printf("%lld  %d %s\n", p->ts, p->id, p->stat);
	}
}

void	release_forks(t_philo *p)
{
	/*
	if (p->id % 2)
	{
		pthread_mutex_unlock(&p->ta->forks[p->left]);
		pthread_mutex_unlock(&p->ta->forks[p->right]);
	}
	else
	{
		pthread_mutex_unlock(&p->ta->forks[p->right]);
		pthread_mutex_unlock(&p->ta->forks[p->left]);
	}
	*/
	pthread_mutex_unlock(&p->ta->forks[p->left]);
	pthread_mutex_unlock(&p->ta->forks[p->right]);
}

int	ft_atoi(char *n)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			return (-1);
		i++;
	}
	while (n[i] && n[i] >= '0' && n[i] <= '9')
	{
		res = (res * 10) + (n[i] - '0');
		i++;
	}
	return (res);
}

long	ft_atol(char *n)
{
	long	i;
	long	res;

	i = 0;
	res = 0;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == 32)
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			return (-1);
		i++;
	}
	while (n[i] && n[i] >= '0' && n[i] <= '9')
	{
		res = (res * 10) + (n[i] - '0');
		i++;
	}
	return (res);
}
