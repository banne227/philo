/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   needed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:22:31 by banne             #+#    #+#             */
/*   Updated: 2026/03/06 12:53:32 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->data->simulation_stop == 1)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_action(philo, "has taken a fork");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	eat(t_philo *philo)
{
	if (philo->data->simulation_stop == 1)
		return ;
	pthread_mutex_lock(&philo->data->simulation_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->data->simulation_lock);
	print_action(philo, "is eating");
	philo->eat_count++;
	if (philo->data->must_eat_count != -1
		&& philo->eat_count >= philo->data->must_eat_count)
	{
		pthread_mutex_lock(&philo->data->simulation_lock);
		philo->data->finished_philos++;
		pthread_mutex_unlock(&philo->data->simulation_lock);
	}
	usleep(philo->data->time_to_eat * 1000);
}

void	sleep_philo(t_philo *philo)
{
	if (philo->data->simulation_stop == 1)
		return ;
	print_action(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	if (philo->data->simulation_stop == 1)
		return ;
	print_action(philo, "is thinking");
}
