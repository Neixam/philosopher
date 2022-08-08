/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 10:25:46 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/06 15:14:12 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "waiting.h"
#include <sys/time.h>
#include <unistd.h>

unsigned long	gettime(void)
{
	struct timeval	actual;

	gettimeofday(&actual, 0);
	return ((actual.tv_sec * 1000) + (actual.tv_usec / 1000));
}

void	waiting(unsigned long waiting_time)
{
	usleep(waiting_time * 1000);
}
