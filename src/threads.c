/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/07/29 14:36:44 by saandria         ###   ########.fr       */
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
	p.threads = malloc(sizeof(pthread_t) * (t_num));
	p.id = 1;
	i = 0;
	while (1)
	{
		while (i < t_num)
		{
			pthread_create(&p.threads[i], NULL, to_do, &p);
			pthread_join(p.threads[i], NULL);
			i++;
			p.id++;
		}
	}
	printf("\033[1;91mCOMPLETED\033[0m\n");
	free(p.threads);
	pthread_exit(NULL);
}
