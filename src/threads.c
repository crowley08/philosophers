/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:14:48 by saandria          #+#    #+#             */
/*   Updated: 2024/07/29 10:44:51 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*to_do(void *id)
{
	long	tid;

	tid = (long)id;
	printf("thread %ld starts\n", tid);
	printf("\033[1;6mloading.....\n\033[0m");
	sleep(3);
	printf("thread %ld ends\n", tid);
	pthread_exit(NULL);
}

int	main(int ac, char *av[])
{
	pthread_t	*threads;
	long			t_num;
	long			i;

	if (ac > 1)
		t_num = atol(av[1]);
	else
		return (0);
	threads = malloc(sizeof(pthread_t) * (t_num));
	i = 0;
	while (i < t_num)
	{
		printf("\033[1;93mCreating thread %ld\033[0m\n", i + 1);
		pthread_create(&threads[i], NULL, to_do, (void *)(i + 1));
		pthread_join(threads[i], NULL);
		i++;
	}
	printf("\033[1;91mCOMPLETED\033[0m\n");
	free(threads);
	pthread_exit(NULL);
}
