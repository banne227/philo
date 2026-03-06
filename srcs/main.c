/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:13:31 by banne             #+#    #+#             */
/*   Updated: 2026/03/06 12:53:28 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		id;

	data.start_time = get_time();
	if (init_data(&data, argc, argv) < 0)
		return (printf("Error initializing data\n"), -1);
	if (data.philo_count == 1)
		return (start_one_philo(&data));
	id = 0;
	while (id < data.philo_count)
	{
		data.philos[id].last_meal = data.start_time;
		pthread_create(&data.philos[id].thread, NULL, philo_routine,
			&data.philos[id]);
		id++;
		if (data.philo_count % 2 == 0)
			usleep(100);
	}
	pthread_create(&data.monitor_thread, NULL, monitor, &data);
	id = 0;
	while (id < data.philo_count)
		pthread_join(data.philos[id++].thread, NULL);
	pthread_join(data.monitor_thread, NULL);
	free_data(&data);
	return (0);
}
