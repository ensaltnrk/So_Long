/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 02:42:12 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/28 02:42:14 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move(t_data *data, int i, int j)
{
	if (data->map[j][i] == 'E')
	{
		if (data->collectables != 0)
			return (0);
		ft_printf("Step.s : %i\n", ++data->counter);
		ft_printf("The End\n");
		exit_game(data);
	}
	if (data->map[j][i] == '0')
	{
		data->map[j][i] = 'P';
		data->playerfirst = i;
		data->playerlast = j;
		data->counter++;
	}
	if (data->map[j][i] == 'C')
	{
		data->map[j][i] = 'P';
		data->playerfirst = i;
		data->playerlast = j;
		data->collectables--;
		data->counter++;
	}
	return (1);
}
