/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoltura <dpoltura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:46:49 by dpoltura          #+#    #+#             */
/*   Updated: 2024/02/27 14:32:46 by dpoltura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_thread	*thread;
	
	thread = NULL;
	if (argc != 6 || !is_digit(argv))
		return (1);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	init_philo(philo, argv);
	print_philo(philo);
	init_thread(&thread, philo);
	create_thread(thread);
	free(philo);
	free_thread(thread);
	return (0);
}

int	is_digit(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_atoi(argv[i]) || ft_atoi(argv[i]) == 1)
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

void	init_philo(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->num_times_to_eat = ft_atoi(argv[5]);
}

void	print_philo(t_philo *philo)
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

void	*init_thread(t_thread **thread, t_philo *philo)
{
	int	i;
	t_thread	*first;

	i = philo->num_of_philos;
	*thread = malloc(sizeof(t_thread));
	if (!(*thread))
		return (NULL);
	(*thread)->prev = NULL;
	init_thread_values(*thread);
	first = *thread;
	while (i - 1)
	{
		(*thread)->next = malloc(sizeof(t_thread));
		if (!(*thread)->next)
			return (NULL);
		(*thread)->next->prev = *thread;
		*thread = (*thread)->next;
		init_thread_values(*thread);
		i--;
	}
	*thread = first;
	return ((void*) 1);
}

void	init_thread_values(t_thread *thread)
{
	thread->thread = 0;
	thread->id = 0;
	thread->eating = 0;
	thread->meals_eaten = 0;
	thread->last_meal = 0;
	thread->start_time = 0;
	thread->dead = NULL;
	thread->r_fork = NULL;
	thread->l_fork = NULL;
	thread->write_lock = NULL;
	thread->dead_lock = NULL;
	thread->meal_lock = NULL;
	thread->next = NULL;
}

void	free_thread(t_thread *thread)
{
	t_thread	*current;
	
	current = thread;
	while (thread)
	{
		current = current->next;
		free(thread);
		thread = current;
	}
}

void	create_thread(t_thread *thread)
{
	t_thread	*current;

	current = thread;
	while (current)
	{
		pthread_create(&current->thread, NULL, &routine, NULL);
		usleep(50);
		current = current->next;
	}
	current = thread;
	while (current)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
	}
}

void	*routine()
{
	printf("thread test\n");
	return (NULL);
}
