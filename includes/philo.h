/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:31 by saandria          #+#    #+#             */
/*   Updated: 2024/08/05 17:08:45 by saandria         ###   ########.fr       */
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
//	pthread_mutex_t	mutex;
	char			*stat;
	int				id;
	int				left;
	int				right;
	long long		ts;
	int				eaten;
	t_table			*ta;
}					t_philo;

typedef struct s_table
{
	t_philo			*p;
	pthread_mutex_t	protec;
	pthread_mutex_t	*forks;
	int				p_num;
	int				eat;
	long long		start;
	t_time			t;
}					t_table;

void		*to_do(void *p);
void		ph_think(t_philo *p);
void		ph_eat(t_philo *p);
void		ph_sleep(t_philo *p);
void		ph_died(t_philo *p);
int			ft_atoi(char *n);
long		ft_atol(char *n);
void		init_time(t_table *t, char *av[]);
void		print_stat(t_philo *p, int i, char *status);
void		take_forks(t_philo *p);
void		release_forks(t_philo *philo);
void		init_table(t_table *table);
long long	get_time(void);
void		ph_threads(t_table *table, char *av[]);
int			eaten_n_times(t_philo *p);

#endif