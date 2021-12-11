/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:12:57 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/11 13:45:00 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_stats(t_philo *philo, int instruction, unsigned long long time)
{
	if (pthread_mutex_lock(&philo->args->write))
		return (1);
	if (instruction == FORK)
		printf("%llu %d has taken a fork\n", time, philo->id);
	if (instruction == EAT)
		printf("%llu %d is eating\n", time, philo->id);
	if (instruction == SLEEP)
		printf("%llu %d is sleeping\n", time, philo->id);
	if (instruction == THINK)
		printf("%llu %d is thinking\n", time, philo->id);
	pthread_mutex_unlock(&philo->args->write);
	return (0);
}

int		ft_isdigit(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return(0);
			j++;
		}
		i++;
	}
	return (1);
}

long    ft_atoi(const char *str)
{
	int		i;
	size_t	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 4294967295 && sign == -1)
			return (0);
		else if (result > 4294967295 && sign == 1)
			return (-1);
		i++;
	}
	return ((int)result * sign);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
