/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:35:31 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/28 00:35:32 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_player(t_data *data, int height, int width)
{
	mlx_put_image_to_window(data->mlx, data->win, data->player,
		width * 64, height * 64);
	data->playerfirst = width;
	data->playerlast = height;
}

void	put_collectable(t_data *data, int height, int width)
{	
	mlx_put_image_to_window(data->mlx, data->win, data->collectable,
		width * 64, height * 64);
	data->collectables += 1;
}

void	get_img(t_data *data)
{
	int	i;
	int	j;

	data->player = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &i, &j);
	data->collectable = mlx_xpm_file_to_image(data->mlx, "./img/item.xpm",
			&i, &j);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &i, &j);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &i, &j);
	data->exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &i, &j);
	if (!data->player || !data->collectable || !data->floor
		|| !data->wall || !data->exit)
	{
		ft_printf("Error\n");
		exit_game(data);
	}
}

void	put_img(t_data *data)
{
	int	i;
	int	j;

	data->collectables = 0;
	j = -1;
	while (data->map[++j])
	{
		i = -1;
		while (data->map[j][++i])
		{
			if (data->map[j][i] == 'C')
				put_collectable(data, j, i);
			if (data->map[j][i] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall, i * 64, j * 64);
			if (data->map[j][i] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->floor, i * 64, j * 64);
			if (data->map[j][i] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->exit, i * 64, j * 64);
			if (data->map[j][i] == 'P')
				put_player(data, j, i);
		}
	}
}
