/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:13:02 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/13 11:03:20 by mbifenzi         ###   ########.fr       */
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

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIE 5

typedef struct s_args
{
	int 				philos;
	int 				die;
	int 				eat;
	int 				sleep;
	int 				meals;
	pthread_mutex_t		*fork;
	pthread_mutex_t		is_eating;
	pthread_mutex_t		write;
}				t_args;

typedef struct	s_philo
{
	pthread_t			thread;

	int					eating_index;
	unsigned long long	last_meal;
	unsigned long long	start;
	int					id;
	int					increment_meal;
	int					all_philo_meals;
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
void	sleepy(unsigned long long duration);
/*exe*/
void				*execute_exe(void *idk);
/*print*/
int					print_stats(t_philo *philo, int instruction, unsigned long long time);
/*supervisor*/
int		supervisor(t_philo *philo);

#endif