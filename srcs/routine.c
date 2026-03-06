/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:46:13 by banne             #+#    #+#             */
/*   Updated: 2026/03/06 12:53:42 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	int		finish;

	finish = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->simulation_stop == 1)
			break ;
		pthread_mutex_lock(&philo->data->simulation_lock);
		if (philo->data->must_eat_count != -1
			&& philo->data->finished_philos >= philo->data->must_eat_count)
			finish = 1;
		pthread_mutex_unlock(&philo->data->simulation_lock);
		if (finish)
			break ;
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_philo(philo);
		think(philo);
		usleep(50);
	}
	return (NULL);
}

void	*routine_one_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->forks[0]);
	print_action(philo, "has taken a fork");
	while (get_time() - philo->data->start_time < philo->data->time_to_die)
		usleep(100);
	print_action(philo, "died");
	return (NULL);
}

int	start_one_philo(t_data *data)
{
	pthread_t	one_philo_thread;

	pthread_create(&one_philo_thread, NULL,
		&routine_one_philo, &data->philos[0]);
	pthread_join(one_philo_thread, NULL);
	free_data(data);
	return (0);
}
