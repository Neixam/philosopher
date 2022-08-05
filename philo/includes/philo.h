/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:08:53 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 15:12:18 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int	nb_ph;
	int	tm_to_die;
	int	tm_to_eat;
	int	tm_to_slp;
	int	nb_eat;
}	t_philo;

t_philo	init_philo(void);

#endif
