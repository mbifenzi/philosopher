/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:47:47 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/14 15:49:53 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	max_meals_check(t_philo *philo)
{
	if (philo->args->meals != 0 && philo->args->meals != -1)
	{
		if (philo->args->all_philo_meals == philo->args->philos)
			return (1);
	}
	return (0);
}

int	supervisor(t_philo *philo)
{
	int	i;
	int	j;

	i = 1;
	while (i)
	{
		j = 0;
		while (j < philo->args->philos)
		{
			pthread_mutex_lock(&philo->args->is_eating);
			if (max_meals_check(philo))
				return (1);
			if (philo[j].eating_index == 0
				&& (unsigned long long)philo->args->die
				< time_after(philo[j].last_meal))
			{
				print_stats(&philo[j], DIE, time_after(philo->start));
				i = 0;
				break ;
			}
			pthread_mutex_unlock(&philo->args->is_eating);
			j++;
		}
	}
	return (1);
}
