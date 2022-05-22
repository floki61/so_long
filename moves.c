/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:29:39 by oel-berh          #+#    #+#             */
/*   Updated: 2022/05/22 00:23:15 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_data *img)
{
	search_map(img, 'P');
	if (keycode == 53 || keycode == 0 || keycode == 13)
		moves1(keycode, img);
	else if (keycode == 1 || keycode == 2)
		moves2 (keycode, img);
	return (0);
}

void	moves3(t_data *img, int py, int px)
{
	if (img->map[py][px] == 'C')
		img->c--;
	if (img->map[py][px] == 'E' && img->c == 0)
		exit (0);
	else if (img->map[py][px] == 'E')
		return ;
	img->map[img->py][img->px] = '0';
	img->map[py][px] = 'P';
	mlx_clear_window (img->mlx, img->mlx_win);
	draw (img);
}

void	moves1(int keycode, t_data *img)
{
	int	px;
	int	py;

	px = img->px;
	py = img->py;
	if (keycode == 53)
		exit(0);
	else if (keycode == 0 && img->map[py][px - 1] != '1')
	{
		img->relative_path2 = "./img/dbl3.xpm";
		px--;
	}
	else if (keycode == 13 && img->map[py - 1][px] != '1')
	{
		img->relative_path2 = "./img/dbl4.xpm";
		py--;
	}
	moves3 (img, py, px);
}

void	moves2(int keycode, t_data *img)
{
	int	px;
	int	py;

	px = img->px;
	py = img->py;
	if (keycode == 1 && img->map[py + 1][px] != '1')
	{
		img->relative_path2 = "./img/dbl.xpm";
		py++;
	}
	else if (keycode == 2 && img->map[py][px + 1] != '1')
	{
		img->relative_path2 = "./img/dbl2.xpm";
		px++;
	}
	moves3 (img, py, px);
}
