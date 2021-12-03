/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:13:02 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/03 16:18:24 by mbifenzi         ###   ########.fr       */
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


typedef struct s_data
{
				int philos;
				int die;
				int eat;
				int sleep;
				int meals;
				int forks;
}				t_data;
typedef struct s_thread
{
	int philos;
	
	
}	t_thread;
/*libft*/
long	ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_isdigit(char **argv);
int		error(char *error);
#endif