/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ambouren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:41:13 by ambouren          #+#    #+#             */
/*   Updated: 2022/08/06 15:23:54 by ambouren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "data.h"

int	main(int ac, char **av)
{
	t_data	data;

	data = init_data();
	if (parsing(ac, av, &data))
		return (1);
	if (init_philos(&data))
		return (1);
	if (launch_philos(&data))
		return (1);
	destroy_data(&data);
	return (0);
}
