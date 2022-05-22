/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:07:40 by oel-berh          #+#    #+#             */
/*   Updated: 2022/05/22 00:23:56 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	drawing(char map, t_data *img, t_node *var)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image
		(img->mlx, "./img/ground.xpm", &(img->img_width), &(img->img_height));
	mlx_put_image_to_window
		(img->mlx, img->mlx_win, img->img, var->k * 80, var->n * 80);
	if (map == '1')
		img->relative_path = "./img/block_02.xpm";
	else if (map == '0')
		img->relative_path = "./img/ground.xpm";
	else if (map == 'P' && img->indx == -1)
		img->relative_path = "./img/dbl.xpm";
	else if (map == 'E' && img->c != 0)
		img->relative_path = "./img/por.xpm";
	else if (map == 'E' && img->c == 0)
		img->relative_path = "./img/port2.xpm";
	else if (map == 'P')
		img->relative_path = img->relative_path2;
	else if (map == 'C')
		img->relative_path = "./img/9ndoss.xpm";
	img->img = mlx_xpm_file_to_image
		(img->mlx, img->relative_path, &(img->img_width), &(img->img_height));
	mlx_put_image_to_window
		(img->mlx, img->mlx_win, img->img, var->k * 80, var->n * 80);
}

void	draw(t_data *img)
{
	t_node	*var;

	var = malloc(sizeof(t_node));
	var->n = 0;
	while (img->map[var->n])
	{
		var->k = 0;
		while (img->map[var->n][var->k])
		{
			drawing (img->map[var->n][var->k], img, var);
			var->k++;
		}
		var->n++;
	}
	img->indx++;
	ft_putstr (ft_itoa(img->indx));
}

int	draw_map(t_data *img, t_node *var)
{
	int		i;
	int		j;
	int		n;
	int		k;

	n = 0;
	k = 0;
	i = ft_strlen(img->map[0]);
	j = var->lenght;
	img->indx = -1;
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, i * 80, j * 80, "game");
	draw(img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 17, 0, destroy, img);
	mlx_loop(img->mlx);
	return (0);
}
