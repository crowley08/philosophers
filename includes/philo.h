/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:31 by saandria          #+#    #+#             */
/*   Updated: 2024/08/01 13:42:55 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_time
{
	long	to_die;
	long	to_eat;
	long	to_sleep;
}			t_time;

typedef struct s_philo
{
	pthread_t		threads;
	pthread_mutex_t	mutex;
	char			*stat;
	int				id;
	int				eaten;
	t_time			t;
}					t_philo;

typedef struct s_table
{
	t_philo	*p;
	int		p_num;
}			t_table;

void	*to_do(void *p);
void	ph_think(t_philo *p);
void	ph_eat(t_philo *p);
void	ph_sleep(t_philo *p);
void	ph_died(t_philo *p);
int		ft_atoi(char *n);
long	ft_atol(char *n);
void	init_time(t_philo *p, char *av[]);

#endif