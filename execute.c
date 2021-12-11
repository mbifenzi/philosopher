/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:38:23 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/11 12:17:39 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_steps(t_philo *philo)
{
	pthread_mutex_lock(&philo->args->eat);
	philo->last_meal = time_now();
	philo->eating_index = 1;
	philo->increment_meal++;
	if (philo->increment_meal == philo->args->meals)
		philo->all_philo_meals++;
	print_stats(philo, EAT, philo->start);
	usleep(philo->args->eat * 1000);
	pthread_mutex_unlock(&philo->args->eat);
	philo->eating_index = 0;
}

void	ft_eat(t_philo *philo)
{
	int right;
	int left;


	if (philo->id % 2 == 1)
		right = philo->id % philo->args->philos;
	else
		right = philo->id - 1;
	if (philo->id % 2 == 1)
		left = philo->id - 1;
	else
		left = philo->id % philo->args->philos;
	pthread_mutex_lock(&philo->args->fork[right]);
	print_stats(philo, FORK, time_after(philo->start));
	pthread_mutex_lock(&philo->args->fork[left]);
	print_stats(philo, FORK, time_after(philo->start));
	ft_eat_steps(philo);
	pthread_mutex_unlock(&philo->args->fork[right]);
	pthread_mutex_unlock(&philo->args->fork[left]);
}

void	ft_sleep(t_philo *philo)
{
	print_stats(philo, SLEEP, time_after(philo->start));
	usleep(philo->args->sleep * 1000);
}

void	ft_think(t_philo *philo)
{
	print_stats(philo, THINK, time_after(philo->start));
}

void	*execute_exe(void *idk)
{
	t_philo *philo;
	
	philo = (t_philo *)idk;
	if (philo == NULL || philo->args->meals == -1)
		return (NULL);
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
