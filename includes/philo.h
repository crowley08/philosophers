/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saandria <saandria@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:18:31 by saandria          #+#    #+#             */
/*   Updated: 2024/08/12 11:15:04 by saandria         ###   ########.fr       */
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
	long		to_die;
	long		to_eat;
	long		to_sleep;
	long long	last_eat;
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
	pthread_t		death_threads;
	pthread_mutex_t	mutex;
	pthread_mutex_t	dead;
	t_philo			*p;
	pthread_mutex_t	*forks;
	int				p_num;
	long long		start;
	int				one_is_dead;
}					t_table;

void		*to_do(void *p);
void		ph_think(t_philo *p);
void		ph_eat(t_philo *p);
void		ph_sleep(t_philo *p);
int			ph_atoi(char *n);
long		ph_atol(char *n);
void		init_time(t_philo *p, char *av[]);
void		print_stat(t_philo *p);
void		take_forks(t_philo *p);
void		release_forks(t_philo *p);
void		init_table(t_table *table);
long long	get_time(void);
void		ph_threads(t_table *table, char *av[]);
void		init_forks(t_table *table);
void		init_threads(t_table *table, char *av[]);
void		join_threads(t_table *table);
void		destroy_mutex(t_table *table);
void		is_dead(t_table *table);
int			no_one_died(t_table *table);
int			check_death(t_table *table, int i);
void		*death_thread(void *t);
void		clean_threads(t_table *table);
void		ph_usleep(long ts);
void		free_all(t_table *table);
int			atoi_av(char *n);

#endif