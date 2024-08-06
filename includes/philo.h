/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:31 by saandria          #+#    #+#             */
/*   Updated: 2024/08/06 13:15:20 by saandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_table	t_table;
typedef struct s_philo	t_philo;

typedef struct s_time
{
	long	to_die;
	long	to_eat;
	long	to_sleep;
}			t_time;

typedef struct s_philo
{
	pthread_t		threads;
	char			*stat;
	int				id;
	int				left;
	int				right;
	int				eat;
	int				eaten;
	long long		ts;
	t_table			*ta;
	t_time			t;
}					t_philo;

typedef struct s_table
{
	pthread_mutex_t	mutex;
	t_philo			*p;
	pthread_mutex_t	*forks;
	int				p_num;
	long long		start;
}					t_table;

void		*to_do(void *p);
void		ph_think(t_philo *p);
void		ph_eat(t_philo *p);
void		ph_sleep(t_philo *p);
void		ph_died(t_philo *p);
int			ft_atoi(char *n);
long		ft_atol(char *n);
void		init_time(t_philo *p, char *av[]);
void		print_stat(t_philo *p);
void		take_forks(t_philo *p);
void		release_forks(t_philo *philo);
void		init_table(t_table *table);
long long	get_time(void);
void		ph_threads(t_table *table, char *av[]);

#endif