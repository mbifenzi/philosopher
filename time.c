/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:29:19 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/14 16:09:13 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	time_after(unsigned long long start)
{
	struct timeval	after;

	gettimeofday(&after, NULL);
	return (((after.tv_sec * 1000) + (after.tv_usec / 1000)) - start);
}

unsigned long long	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	sleepy(unsigned long long duration)
{
	while (time_now() < duration)
		usleep(10);
}
