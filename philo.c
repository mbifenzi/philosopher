/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:34 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/09 14:54:21 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *error)
{
	write(2, error, ft_strlen(error));
	return (0);
}

int	ft_protection(t_args *args, int argc, char **argv)
{
    if (argc != 5 && argc != 6)
		return (error("INVALID ARGUMENTS\n"));
	if (!ft_isdigit(argv))
		return(error("not a digit or negative something\n"));
	args->philos = ft_atoi(argv[1]);
	args->die = ft_atoi(argv[2]);
	args->eat = ft_atoi(argv[3]);
	args->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->meals = ft_atoi(argv[5]);
		if (args->meals <= 0)
			return (error("negative something\n"));
	}
	return (1);
}

void	init_mutexs(t_philo *philo, t_args *args)
{
	int i;

	i = 0;
	philo->fork = malloc(sizeof(pthread_mutex_t) * args->philos);
	while (i < args->philos)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&philo->write, NULL);
	pthread_mutex_init(&philo->eat, NULL);
}
t_philo		*init_philo(t_philo	*philo, t_args *args)
{
	int i;
	i = 0;
	
	philo = malloc(sizeof(t_philo) * args->philos);
	while (i < args->philos)
	{
		philo[i].id = i;
		philo[i].increment_meal = 0;
		philo[i].last_meal = time_now();
		philo[i].start = philo->last_meal;
		i++;
	}
	return(philo);
}


void	execute_threads(t_args *args, t_philo *philo)
{
	int i;
	
	i = 0;
	while(i < args->philos)
	{
		pthread_create(&philo[i].thread, NULL, execute_exe, &philo[i]);
		i++;
	}
	supervisor();
}

int main(int argc, char **argv)
{
	t_args		*args;
	t_philo		*philo;
	
	args = NULL;
	philo = NULL;
	if (argc == 5 || argc == 6)
		args = malloc(sizeof(t_args) * (ft_atoi(argv[1])));
	if (!ft_protection(args, argc, argv))
		exit (0);
	philo = init_philo(philo, args); 
	init_mutexs(philo, args);
	execute_threads(args, philo);
	
	return (0);
}
