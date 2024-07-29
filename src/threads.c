/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/07/29 23:34:18 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_philo			p;
	int			t_num;
	int			i;

	if (ac > 1)
		t_num = atoi(av[1]);
	else
		return (0);
	p.threads = malloc(sizeof(pthread_t) * (t_num + 1));
	p.mutex = malloc(sizeof(pthread_mutex_t) * (t_num + 1));
	p.id = 0;
	i = 0;
	while (i < t_num)
	{
		pthread_mutex_init(&p.mutex[i], NULL);
		pthread_create(&p.threads[i], NULL, to_do, &p);
		i++;
		p.id++;
	}
	i = 0;
	while (i < t_num)
	{
		pthread_join(p.threads[i], NULL);
		pthread_mutex_destroy(&p.mutex[i]);
		i++;
	}
	free(p.threads);
	free(p.mutex);
	pthread_exit(NULL);
}
