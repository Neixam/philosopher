/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:25:46 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/08 13:36:50 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "waiting.h"
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

unsigned long	gettime(void)
{
	struct timeval	actual;

	gettimeofday(&actual, 0);
	return ((actual.tv_sec * 1000) + (actual.tv_usec / 1000));
}

void	taking_fork(t_philo *philo)
{
	if (philo->my_id % 2)
	{
		pthread_mutex_lock(&philo->my_fork);
		say(philo, "has taken a fork", 1);
		pthread_mutex_lock(philo->r_fork);
		say(philo, "has taken a fork", 1);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		say(philo, "has taken a fork", 1);
		pthread_mutex_lock(&philo->my_fork);
		say(philo, "has taken a fork", 1);
	}
}

int	do_thing(t_data *data, t_philo *philo)
{
	if (philo->nb_eat
		&& (gettime() - philo->last_eat)
		> (unsigned long)data->tm_to_die)
	{
		dying(philo);
		data->dead = 1;
		pthread_mutex_unlock(&data->eating);
		return (1);
	}
	pthread_mutex_unlock(&data->eating);
	return (0);
}

void	waiting(t_philo *philo, unsigned long waiting_time)
{
	unsigned long	i;

	waiting_time *= 1000;
	i = 10000;
	while (waiting_time)
	{
		pthread_mutex_lock(philo->eating);
		if (*philo->dead)
		{
			pthread_mutex_unlock(philo->eating);
			return ;
		}
		pthread_mutex_unlock(philo->eating);
		usleep(i);
		if (waiting_time < i)
			i = waiting_time;
		waiting_time -= i;
	}
}
