/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:23:34 by banne             #+#    #+#             */
/*   Updated: 2025/11/27 12:32:57 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long			last_meal;
	int				eat_count;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	int				finished_philos;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	simulation_lock;
	int				simulation_stop;
	pthread_t		monitor_thread;
	t_philo			*philos;
}				t_data;

int		ft_atoi(const char *str);
int		parse_args(int argc, char **argv, t_data *data);
long	ft_atol(const char *str);
void	free_data(t_data *data);
int		init_data(t_data *data, int argc, char **argv);
void	take_forks(t_philo *philo);
void	put_forks(t_philo *philo);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	print_action(t_philo *philo, char *msg);
long	get_time(void);
void	think(t_philo *philo);
void	*philo_routine(void *arg);
void	*monitor(void *arg);
int		start_one_philo(t_data *data);
void	*routine_one_philo(void *arg);

#endif