/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:12:34 by mbifenzi          #+#    #+#             */
/*   Updated: 2021/12/03 13:25:40 by mbifenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *error)
{
	write(2, error, ft_strlen(error));
	return (0);
}
int	ft_protection(t_data *args, int argc, char **argv)
{
    if (argc != 5 && argc != 6)
        return (error("INVALID ARGUMENTS\n"));
	args->philos = ft_atoi(argv[1]);
	args->die = ft_atoi(argv[2]);
	args->eat = ft_atoi(argv[3]);
	args->sleep = ft_atoi(argv[4]);
	if ( args->philos < 0 || args->die < 0 || args->eat < 0 || args->sleep < 0)
		return (error("negative something\n"));
	if (argc == 6)
	{		
		args->meals = ft_atoi(argv[5]);
		if (args->meals <= 0)
			return (error("negative something\n"));
	}		
	return(1);
}

int main(int argc, char **argv)
{
	t_data *args;
	args = malloc(sizeof(t_data));
	if (!ft_protection(args, argc, argv))
		exit (0);
	
	

}
