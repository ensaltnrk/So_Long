/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealtinor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:35:01 by ealtinor          #+#    #+#             */
/*   Updated: 2022/06/28 00:35:04 by ealtinor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_a(t_data *data, int c)
{
	int	i;
	int	j;
	int	k;

	i = data->playerfirst;
	j = data->playerlast;
	if (c == 0)
	{
		i--;
		if (data->map[j][i] == '1')
			return (0);
		k = move(data, i, j);
		if (!k)
			return (0);
		data->map[j][i + 1] = '0';
	}
	ft_printf("Step.a : %i\n", data->counter);
	return (1);
}

int	check_d(t_data *data, int c)
{
	int	i;
	int	j;
	int	k;

	i = data->playerfirst;
	j = data->playerlast;
	if (c == 2)
	{
		i++;
		if (data->map[j][i] == '1')
			return (0);
		k = move(data, i, j);
		if (!k)
			return (0);
		data->map[j][i - 1] = '0';
	}
	ft_printf("Step.d : %i\n", data->counter);
	return (1);
}

int	check_w(t_data *data, int c)
{
	int	i;
	int	j;
	int	k;

	i = data->playerfirst;
	j = data->playerlast;
	if (c == 13)
	{
		j--;
		if (data->map[j][i] == '1')
			return (0);
		k = move(data, i, j);
		if (!k)
			return (0);
		data->map[j + 1][i] = '0';
	}
	ft_printf("Step.w : %i\n", data->counter);
	return (1);
}

int	check_s(t_data *data, int c)
{
	int	i;
	int	j;
	int	k;

	i = data->playerfirst;
	j = data->playerlast;
	if (c == 1)
	{
		j++;
		if (data->map[j][i] == '1')
			return (0);
		k = move(data, i, j);
		if (!k)
			return (0);
		data->map[j - 1][i] = '0';
	}
	ft_printf("Step.s : %i\n", data->counter);
	return (1);
}

int	control_key(int c, t_data *data)
{
	int	step;

	if (c == 13)
		step = check_w(data, c);
	if (c == 1)
		step = check_s(data, c);
	if (c == 0)
		step = check_a(data, c);
	if (c == 2)
		step = check_d(data, c);
	if (c == 53)
		exit_game(data);
	if (step)
		put_img(data);
	return (1);
}
