/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 09:08:09 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/08 13:10:43 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include "philo.h"

typedef struct s_data
{
	int				nb_ph;
	int				tm_to_die;
	int				tm_to_eat;
	int				tm_to_slp;
	int				nb_eat;
	int				dead;
	int				stop;
	unsigned long	start_time;
	pthread_mutex_t	eating;
	pthread_mutex_t	mic;
	t_philo			*philos;
}	t_data;

t_data	init_data(void);

int		launch_philos(t_data *data);

int		init_philos(t_data *data);

void	destroy_data(t_data *data);

#endif
