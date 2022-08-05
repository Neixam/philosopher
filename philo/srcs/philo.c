/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:00:43 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 15:15:50 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(void)
{
	t_philo	ret;

	ret.nb_ph = 0;
	ret.tm_to_die = 0;
	ret.tm_to_eat = 0;
	ret.tm_to_slp = 0;
	ret.nb_eat = -1;
}