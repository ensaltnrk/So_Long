/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:03:11 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/25 14:03:16 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "./mlx/mlx.h"

typedef struct s_data
{
	char	**map;
	void	*floor;
	void	*wall;
	void	*player;
	void	*collectable;
	void	*mlx;
	void	*win;
	void	*exit;
	int		fd;
	int		heightmap;
	int		widthmap;
	int		playerfirst;
	int		playerlast;
	int		playercount;
	int		collectablecount;
	int		counter;
	int		collectables;
	int		exitcount;	
}	t_data;

int			read_map(t_data *data, char **av);
int			exit_game(t_data *data);
void		if_wall(t_data *data);
void		check_error(t_data *data);
void		if_character(t_data *data);
void		put_img(t_data *data);
void		get_img(t_data *data);
int			control_key(int c, t_data *data);
int			move(t_data *data, int i, int j);
int			check_a(t_data *data, int c);
int			check_d(t_data *data, int c);
int			check_w(t_data *data, int c);
int			check_s(t_data *data, int c);
int			control_key(int c, t_data *data);

#endif
