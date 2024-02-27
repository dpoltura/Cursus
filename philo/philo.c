/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:46:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/27 10:52:08 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data *philo;
	
	if (argc != 6 || !is_digit(argv))
		return (1);
	philo = malloc(sizeof(t_data));
	if (!philo)
		return (1);
	init_data(philo, argv);
	print_data(philo);
	free(philo);
	return (0);
}

int	is_digit(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_atoi(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		k = k * 10;
		k += nptr[i] - '0';
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] != ' ')
			k = 0;
		i++;
	}
	return (k);
}

void	init_data(t_data *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->num_times_to_eat = ft_atoi(argv[5]);
}

void	print_data(t_data *philo)
{
	printf(BLUE_COLOR);
	printf("[NB_OF_PHILO: %d]\n", philo->num_of_philos);
	printf(RED_COLOR);
	printf("[TIME_TO_DIE: %zu]\n", philo->time_to_die);
	printf(YELLOW_COLOR);
	printf("[TIME_TO_EAT: %zu]\n", philo->time_to_eat);
	printf(GREEN_COLOR);
	printf("[TIME_TO_SLEEP: %zu]\n", philo->time_to_sleep);
	printf(DEFAULT_COLOR);
	printf("[NB_TIME_TO_EAT: %d]\n", philo->num_times_to_eat);
}