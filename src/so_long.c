/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:31:49 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/28 00:31:50 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	len(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	map_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	check_map(char *str)
{
	size_t	size;

	if (!str)
		return (0);
	size = len(str) - 1;
	if (str[size] == 'r' && str[size - 1] == 'e'
		&& str[size - 2] == 'b' && str[size - 3] == '.')
		return (1);
	else
		map_error();
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		ft_memset(&data, 0, sizeof(t_data));
		check_map(av[1]);
		read_map(&data, av);
		check_error(&data);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, ((data.widthmap - 1) * 64),
				(data.heightmap * 64), "solong");
		get_img(&data);
		put_img(&data);
		mlx_key_hook(data.win, control_key, &data);
		mlx_hook(data.win, 17, 0, (void *)exit_game, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
