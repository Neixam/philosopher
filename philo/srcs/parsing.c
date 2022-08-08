/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:00:47 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/08 14:04:03 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <limits.h>

int	ft_atoi(char *s, int *ret)
{
	long long	value;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
			sign = -1;
	value = 0;
	while (s[i] <= '9' && s[i] >= '0')
	{
		value = value * 10 + (s[i++] - '0');
		if (value * sign < INT_MIN || value * sign > INT_MAX)
			return (1);
	}
	*ret = value * sign;
	if (s[i])
		return (1);
	return (0);
}

int	parsing(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
	{
		printf("Bad number of argument\n");
		return (1);
	}
	if (ft_atoi(av[1], &data->nb_ph) || ft_atoi(av[2], &data->tm_to_die)
		|| ft_atoi(av[3], &data->tm_to_eat)
		|| ft_atoi(av[4], &data->tm_to_slp)
		|| (ac == 6 && ft_atoi(av[5], &data->nb_eat)))
	{
		printf("Bad format of argument\n");
		return (1);
	}
	if (data->nb_ph <= 1 || data->tm_to_die < 0
		|| data->tm_to_eat < 0 || data->tm_to_slp < 0)
	{
		printf("Negative value are forbidden\n");
		return (1);
	}
	return (0);
}
