/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:36:25 by banne             #+#    #+#             */
/*   Updated: 2026/03/06 12:53:26 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	init_philo(t_data *data, int id)
{
	t_philo	philo;

	philo.left_fork = &data->forks[id];
	if (id == data->philo_count - 1)
		philo.right_fork = &data->forks[0];
	else
		philo.right_fork = &data->forks[(id + 1)];
	philo.id = id + 1;
	philo.data = data;
	philo.eat_count = 0;
	return (philo);
}

int	init_data(t_data *data, int argc, char **argv)
{
	int	philo_id;

	data->must_eat_count = -1;
	if (parse_args(argc, argv, data) < 1)
		return (-1);
	data->finished_philos = 0;
	data->philos = malloc(sizeof(t_philo) * data->philo_count);
	if (!data->philos)
		return (-1);
	philo_id = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (!data->forks)
		return (free(data->philos), -1);
	data->simulation_stop = 0;
	pthread_mutex_init(&data->print_lock, NULL);
	pthread_mutex_init(&data->death_lock, NULL);
	pthread_mutex_init(&data->simulation_lock, NULL);
	while (philo_id < data->philo_count)
	{
		pthread_mutex_init(&data->forks[philo_id], NULL);
		data->philos[philo_id] = init_philo(data, philo_id);
		philo_id++;
	}
	return (1);
}
