/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:07:00 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/25 14:07:05 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	horizontalwall(t_data *data)
{
	int	i;
	int	j;

	i = data->widthmap - 1;
	j = 0;
	while (j < i)
	{
		if (data->map[0][j] != '1' || data->map[data->heightmap - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	verticalwall(t_data *data)
{
	int	i;
	int	j;

	i = data->widthmap - 1;
	j = 0;
	while (j < data->heightmap)
	{
		if (data->map[j][0] != '1' || data->map[j][i - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

void	if_wall(t_data *data)
{
	int	horizontal;
	int	vertical;

	vertical = verticalwall(data);
	horizontal = horizontalwall(data);
	if (!vertical || !horizontal)
	{
		ft_printf("Error\n");
		exit_game(data);
	}
}

void	check_count(t_data *data, int height, int width)
{
	if (data->map[height][width] != '1' && data->map[height][width] != '0' &&
		data->map[height][width] != 'P' && data->map[height][width] != 'E' &&
		data->map[height][width] != 'C' && data->map[height][width] != '\n'
	)
	{
		ft_printf("Error\n");
		exit_game(data);
	}
	if (data->map[height][width] == 'C')
		data->collectablecount++;
	if (data->map[height][width] == 'P')
		data->playercount++;
	if (data->map[height][width] == 'E')
		data->exitcount++;
}

void	if_character(t_data *data)
{
	int	width;
	int	height;

	height = 0;
	while (height < data->heightmap - 1)
	{
		width = 0;
		while (width < data->widthmap)
		{
			check_count(data, height, width);
			width++;
		}
		height++;
	}
	if (!(data->playercount == 1 && data->exitcount >= 1
			&& data->collectablecount >= 1))
	{
		ft_printf("Error\n");
		exit_game(data);
	}
}
