/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:13:02 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/07 15:22:22 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_args
{
				int philos;
				int die;
				int eat;
				int sleep;
				int meals;
}				t_args;

typedef struct	s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*forks;
	pthread_mutex_t		eat;
	pthread_mutex_t		write;
	unsigned long long	timenow;
	unsigned long long	timepassed;
	unsigned long long	last_meal;
	unsigned long long	start;
	int					id;
	t_args				*args;
	
}	t_philo;
/*libft*/
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(char **argv);
int		error(char *error);

/*time*/
unsigned long long	time_now(void);
unsigned long long	time_after(unsigned long long	start);


#endif