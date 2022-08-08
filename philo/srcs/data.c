/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 09:04:52 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/06 15:29:40 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdlib.h>
#include "waiting.h"

t_data	init_data(void)
{
	t_data	ret;

	ret.nb_ph = 0;
	ret.tm_to_die = 0;
	ret.tm_to_eat = 0;
	ret.tm_to_slp = 0;
	ret.nb_eat = -1;
	ret.philos = 0;
	ret.dead = 0;
	return (ret);
}

int	init_philos(t_data *data)
{
	int				i;

	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->nb_ph);
	if (!data->philos)
		return (1);
	pthread_mutex_init(&data->mic, NULL);
	pthread_mutex_init(&data->eating, NULL);
	i = -1;
	while (++i < data->nb_ph)
	{
		data->philos[i].my_id = i + 1;
		data->philos[i].start_time = &data->start_time;
		data->philos[i].mic = &data->mic;
		data->philos[i].eating = &data->eating;
		pthread_mutex_init(&data->philos[i].my_fork, NULL);
		data->philos[i].tm_to_die = data->tm_to_die;
		data->philos[i].tm_to_eat = data->tm_to_eat;
		data->philos[i].tm_to_slp = data->tm_to_slp;
		data->philos[i].nb_eat = data->nb_eat;
		data->philos[i].dead = &data->dead;
	}
	i = -1;
	while (++i < data->nb_ph)
		data->philos[i].r_fork = &data->philos[(i + 1) % data->nb_ph].my_fork;
	return (0);
}

void	check_die(t_data *data)
{
	int				i;

	while (1)
	{
		i = -1;
		while (++i < data->nb_ph)
		{
			pthread_mutex_lock(&data->eating);
			if (gettime() - data->philos[i].last_eat > (unsigned long)data->tm_to_die)
			{
				dying(&data->philos[i]);
				data->dead = 1;
				pthread_mutex_unlock(&data->eating);
				return ;
			}
			pthread_mutex_unlock(&data->eating);
			waiting(100);
		}
		i = 0;
		while (data->nb_eat != -1 && i < data->nb_ph && data->philos[i].nb_eat == 0)
			i++;
		if (i == data->nb_ph)
			return ;
	}
}

void	destroy_data(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&data->mic);
	pthread_mutex_destroy(&data->eating);
	while (++i < data->nb_ph)
		pthread_mutex_destroy(&data->philos[i].my_fork);
	free(data->philos);
}

int	launch_philos(t_data *data)
{
	int			i;

	i = -1;
	data->start_time = gettime();
	while (++i < data->nb_ph)
	{
		pthread_create(&data->philos[i].id, NULL, philo, data->philos + i);
		data->philos[i].last_eat = gettime();
	}
	check_die(data);
	i = -1;
	while (++i < data->nb_ph)
		pthread_join(data->philos[i].id, NULL);
	return (0);
}
