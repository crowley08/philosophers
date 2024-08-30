/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 17:16:34 by saandria          #+#    #+#             */
/*   Updated: 2024/08/30 17:33:48 by saandria         ###   ########.fr       */
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

void	*ph_monitor(void *t)
{
	t_table		*table;
	int			i;

	table = (t_table *)t;
	while (table->one_is_dead == 0 && table->everyone_ate == 0)
	{
		i = 0;
		if (check_ate(table))
			break ;
		while (i < table->p_num)
		{
			if (check_death(table, i))
				break ;
			i++;
		}
	}
	return (NULL);
}
