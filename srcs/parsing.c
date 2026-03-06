/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: banne <banne@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 08:30:08 by banne             #+#    #+#             */
/*   Updated: 2026/03/06 12:53:38 by banne            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	parse_args(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		return (-1);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
		if (ft_atoi(argv[i]) <= 0)
			return (-1);
		if (ft_atol(argv[i]) > 2147483647)
			return (-1);
	}
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	return (1);
}
