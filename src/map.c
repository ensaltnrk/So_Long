/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:35:46 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/28 00:35:47 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	witdh_of_map(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i] - 1 == '\n')
		i--;
	return (i);
}

int	add_line(t_data *data, char	*line)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!line)
		return (0);
	data->heightmap++;
	tmp = (char **)malloc(sizeof(char *) * (data->heightmap + 1));
	tmp[data->heightmap] = NULL;
	while (i < data->heightmap - 1)
	{
		tmp[i] = data->map[i];
		i++;
	}
	tmp[i] = line;
	if (data->map)
		free(data->map);
	data->map = tmp;
	return (1);
}

void	check_error(t_data *data)
{
	if_wall(data);
	if_character(data);
}

int	exit_game(t_data *data)
{
	int	i;

	i = 0;
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	free(data->mlx);
	while (i < data->heightmap)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	exit(0);
}

int	read_map(t_data *data, char **av)
{
	char	*readmap;

	data->fd = open(av[1], O_RDONLY);
	if (data->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(data->fd);
		if (!(add_line(data, readmap)))
			break ;
	}
	close(data->fd);
	data->widthmap = witdh_of_map(data->map[0]);
	return (1);
}
