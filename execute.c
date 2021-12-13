/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:38:23 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/13 16:56:58 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_eat_steps(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->is_eating);
	philo->last_meal = time_now();
	philo->eating_index = 1;
	print_stats(philo, EAT, time_after(philo->start));
	pthread_mutex_unlock(&philo->args->is_eating);
	sleepy(philo->args->eat + philo->last_meal);
	pthread_mutex_lock(&philo->args->is_eating);
	philo->eating_index = 0;
	philo->increment_meal++;
	if (philo->increment_meal == philo->args->meals)
		philo->all_philo_meals++;
	pthread_mutex_unlock(&philo->args->is_eating);
}

void	ft_eat(t_philo *philo)
{
	int right;
	int left;
	
	// right = (philo->id + 1) % philo->args->philos;
	// left = philo->id;

	if (philo->id % 2 == 0)
		right = (philo->id + 1) % (philo->args->philos);
	else
		right = philo->id;
	if (philo->id % 2 == 0)
		left = philo->id;
	else
		left = (philo->id + 1) % (philo->args->philos);
	pthread_mutex_lock(&philo->args->fork[left]);
	print_stats(philo, FORK, time_after(philo->start));
	pthread_mutex_lock(&philo->args->fork[right]);
	print_stats(philo, FORK, time_after(philo->start));
	ft_eat_steps(philo);
	pthread_mutex_unlock(&philo->args->fork[right]);
	pthread_mutex_unlock(&philo->args->fork[left]);
}

void	ft_sleep(t_philo *philo)
{
	unsigned long long sleep;

	sleep = time_now();
	print_stats(philo, SLEEP, time_after(philo->start));
	sleepy(philo->args->sleep + sleep);
}

void	ft_think(t_philo *philo)
{
	print_stats(philo, THINK, time_after(philo->start));
}

void	*execute_exe(void *idk)
{
	t_philo *philo;
	
	philo = (t_philo *)idk;
	if (philo == NULL || philo->args->meals == 0)
		return (NULL);
	while (1)	
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
