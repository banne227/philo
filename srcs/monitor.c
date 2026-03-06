/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:58:59 by banne             #+#    #+#             */
/*   Updated: 2026/03/06 12:53:30 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	monitor_test(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_lock(&data->simulation_lock);
		if (get_time() - data->philos[i].last_meal > data->time_to_die)
		{
			print_action(&data->philos[i], "died");
			data->simulation_stop = 1;
			pthread_mutex_unlock(&data->simulation_lock);
			return (-1);
		}
		if (data->must_eat_count != -1
			&& data->finished_philos >= data->philo_count)
		{
			data->simulation_stop = 1;
			pthread_mutex_unlock(&data->simulation_lock);
			return (-1);
		}
		pthread_mutex_unlock(&data->simulation_lock);
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (data->simulation_stop == 0)
	{
		if (monitor_test(data) == -1)
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
