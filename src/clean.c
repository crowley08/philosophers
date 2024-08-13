/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:14:07 by saandria          #+#    #+#             */
/*   Updated: 2024/08/13 10:15:08 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	clean_threads(t_table *table)
{
	destroy_mutex(table);
	pthread_mutex_destroy(&table->dead);
	pthread_mutex_destroy(&table->mutex);
	free(table->p);
	free(table->forks);
}

void	free_all(t_table *table)
{
	if (table->p)
		free(table->p);
	if (table->forks)
		free(table->forks);
}

void	*clear(t_table *table, char *s)
{
	free_all(table);
	printf("%s\n", s);
	return (NULL);
}
