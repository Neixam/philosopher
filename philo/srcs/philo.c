/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:00:43 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/06 15:56:13 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "waiting.h"
#include <stdio.h>

void	say(t_philo *philo, char *s)
{
	pthread_mutex_lock(philo->mic);
	if (*philo->dead)
	{
		pthread_mutex_unlock(philo->mic);
		return ;
	}
	printf("%lu %d %s\n", gettime() - *philo->start_time,
		philo->my_id, s);
	pthread_mutex_unlock(philo->mic);
}

void	sleeping(t_philo *philo)
{
	say(philo, "is sleeping");
	waiting(philo->tm_to_slp);
}

void	eating(t_philo *philo)
{

	say(philo, "is eating");
	pthread_mutex_lock(philo->eating);
	philo->last_eat = gettime();
	pthread_mutex_unlock(philo->eating);
	if (philo->nb_eat != -1)
		philo->nb_eat--;
	waiting(philo->tm_to_eat);
}

void	dying(t_philo *philo)
{
	say(philo, "died");
}

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->my_id % 2)
		waiting(philo->tm_to_eat / 10);
	while (!*philo->dead && (philo->nb_eat == -1 || philo->nb_eat > 0))
	{
		pthread_mutex_lock(&philo->my_fork);
		say(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		say(philo, "has taken a fork");
		eating(philo);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(&philo->my_fork);
		sleeping(philo);
		say(philo, "is thinking");
	}
	return (NULL);
}
