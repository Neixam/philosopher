/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:00:47 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/05 15:22:07 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *s, int *ret)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
		if (s[i] == '-')
			sign = -1;
	*ret = 0;
	while (s[i] <= '9' && s[i] >= '0')
		*ret = *ret * 10 + (s[i++] - '0');
	if (s[i])
		return (1);
	return (0);
}

int	parsing(int ac, char **av, t_philo *philo)
{
	if (ac != 5 && ac != 6)
	{
		printf("Bad number of argument\n");
		return (1);
	}
	if (ft_atoi(av[1], &philo->nb_ph) || ft_atoi(av[2], &philo->tm_to_die)
		|| ft_atoi(av[3], &philo->tm_to_eat)
		|| ft_atoi(av[4], &philo->tm_to_slp)
		|| (ac == 6 && ft_atoi(av[5], &philo->nb_eat)))
	{
		printf("Bad format of argument\n");
		return (1);
	}
	return (0);
}
