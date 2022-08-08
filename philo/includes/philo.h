/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:08:53 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/08 12:11:16 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				my_id;
	pthread_t		id;
	unsigned long	*start_time;
	unsigned long	last_eat;
	pthread_mutex_t	*mic;
	pthread_mutex_t	my_fork;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*r_fork;
	int				tm_to_die;
	int				tm_to_eat;
	int				tm_to_slp;
	int				nb_eat;
	int				*dead;
}	t_philo;

void	*philo(void *arg);

void	say(t_philo *philo, char *s, int tie);

void	dying(t_philo *philo);

#endif
