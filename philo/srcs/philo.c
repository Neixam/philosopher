/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:00:43 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/08 12:10:36 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "waiting.h"
#include <stdio.h>

void	say(t_philo *philo, char *s, int tie)
{
	if (tie)
		pthread_mutex_lock(philo->eating);
	pthread_mutex_lock(philo->mic);
	if (*philo->dead)
	{
		if (tie)
			pthread_mutex_unlock(philo->eating);
		pthread_mutex_unlock(philo->mic);
		return ;
	}
	if (tie)
		pthread_mutex_unlock(philo->eating);
	printf("%lu %d %s\n", gettime() - *philo->start_time,
		philo->my_id, s);
	pthread_mutex_unlock(philo->mic);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->my_fork);
	say(philo, "is sleeping", 1);
	waiting(philo, philo->tm_to_slp);
	say(philo, "is thinking", 1);
}

void	eating(t_philo *philo)
{
	say(philo, "is eating", 1);
	pthread_mutex_lock(philo->eating);
	philo->last_eat = gettime();
	if (philo->nb_eat != -1)
		philo->nb_eat--;
	pthread_mutex_unlock(philo->eating);
	waiting(philo, philo->tm_to_eat);
}

void	dying(t_philo *philo)
{
	say(philo, "died", 0);
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(philo->eating);
		if (*philo->dead || (philo->nb_eat != -1 && philo->nb_eat <= 0))
		{
			pthread_mutex_unlock(philo->eating);
			return (NULL);
		}
		pthread_mutex_unlock(philo->eating);
		taking_fork(philo);
		eating(philo);
		sleeping(philo);
	}
}
