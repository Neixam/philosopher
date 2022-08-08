/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:27:07 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/08 13:34:32 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAITING_H
# define WAITING_H
# include "philo.h"
# include "data.h"

void			waiting(t_philo *philo, unsigned long waiting_time);

void			taking_fork(t_philo *philo);

int				do_thing(t_data *data, t_philo *philo);

unsigned long	gettime(void);

#endif
