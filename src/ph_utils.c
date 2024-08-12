/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:16:34 by saandria          #+#    #+#             */
/*   Updated: 2024/08/12 11:16:27 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_stat(t_philo *p)
{
	pthread_mutex_lock(&p->ta->mutex);
	p->ts = get_time() - p->ta->start;
	pthread_mutex_unlock(&p->ta->mutex);
	pthread_mutex_lock(&p->ta->dead);
	if (!p->ta->one_is_dead)
		printf("\033[1;3m%lld  %d %s\n\033[0m", p->ts, p->id, p->stat);
	pthread_mutex_unlock(&p->ta->dead);
}

void	take_forks(t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		print_stat(p);
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		print_stat(p);
	}
	else
	{
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		print_stat(p);
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		print_stat(p);
	}
}

void	release_forks(t_philo *p)
{
	pthread_mutex_unlock(&p->ta->forks[p->left]);
	pthread_mutex_unlock(&p->ta->forks[p->right]);
}

int	atoi_av(char *n)
{
	int	i;

	i = 0;
	if (n[i] == '[')
	{
		i++;
		return(ph_atoi(n + i));
	}
	else
		return (-1);
}

int	ph_atoi(char *n)
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

long	ph_atol(char *n)
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
