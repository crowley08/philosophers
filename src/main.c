/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:08:58 by saandria          #+#    #+#             */
/*   Updated: 2024/08/23 15:00:48 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	alloc_table(t_table *table, char *av[])
{
	table->p_num = ph_atoi(av[1]);
	table->p = malloc(sizeof(t_philo) * table->p_num);
	table->mutex_forks = malloc(sizeof(pthread_mutex_t) * table->p_num);
	table->forks = malloc(sizeof(char) * table->p_num);
	memset((void *)table->forks, '1', table->p_num);
	table->everyone_ate = 0;
	if (!table->p || !table->mutex_forks || !table->forks)
	{
		free_all(table);
		return ;
	}
	table->one_is_dead = 0;
	ph_threads(table, av);
}

int	ph_error(char *error)
{
	printf("%s\n", error);
	return (0);
}

int	main(int ac, char *av[])
{
	t_table		table;

	if (ph_isdigit(av) == 0)
		return (ph_error("invalid arguments!\n"), 0);
	if (ac >= 5 && ac < 7)
		alloc_table(&table, av);
	else
		printf("should be like ./philo 4 300 200 100 [4]\n");
	return (0);
}
