/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:16:34 by saandria          #+#    #+#             */
/*   Updated: 2024/08/03 04:11:14 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	take_forks(t_philo *p)
{
	if (p->id % 2)
	{
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		printf("\033[1;3m%lld  %d is %s\n\033[0m", p->ta->ts, p->id, p->stat);
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		printf("\033[1;3m%lld  %d is %s\n\033[0m", p->ta->ts, p->id, p->stat);
	}
	else
	{
		pthread_mutex_lock(&p->ta->forks[p->right]);
		p->stat = "has taken a fork";
		printf("\033[1;3m%lld  %d is %s\n\033[0m", p->ta->ts, p->id, p->stat);
		pthread_mutex_lock(&p->ta->forks[p->left]);
		p->stat = "has taken a fork";
		printf("\033[1;3m%lld  %d is %s\n\033[0m", p->ta->ts, p->id, p->stat);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->ta->forks[philo->left]);
	pthread_mutex_unlock(&philo->ta->forks[philo->right]);
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
