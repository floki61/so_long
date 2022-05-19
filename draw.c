#include "so_long.h"

int	key_hook(int keycode, t_data *img)
{
	search_map(img, 'P');
	if(keycode == 53 || keycode == 0 || keycode == 13 || keycode == 2 || keycode == 1)
		moves(keycode, img);
	return (0);
}
void	moves(int keycode, t_data *img)
{
	int	px;
	int py;

	px = img->px;
	py = img->py;
	if (keycode == 53)
		exit(0);
	else if (keycode == 0 && img->map[py][px - 1] != '1')
	{
			img->map[py][px] = '0';
			img->map[py][px - 1] = 'P';
			img->px = -1;
	}
	else if (keycode == 13 && img->map[py - 1][px] != '1')
	{
			img->map[py][px] = '0';
			img->map[py - 1][px] = 'P';
			img->px = -3;
	}
	else if (keycode == 1 && img->map[py + 1][px] != '1')
	{
			img->map[py][px] = '0';
			img->map[py + 1][px] = 'P';
			img->px = 0;
	}
	else if (keycode == 2 && img->map[py][px + 1] != '1')
	{
			img->map[py][px] = '0';
			img->map[py][px + 1] = 'P';
			img->px = -2;
	}
	if(img->px == 0 || img->px == -1 || img->px == -2 || img->px == -3)
		draw(img);
}
void	search_map(t_data *img ,char n)
{
	int i;
	int j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while(img->map[i][j])
		{
			if(img->map[i][j] == n)
			{
				img->px = j;
				img->py = i;
				return;
			}
			j++;
		}
		i++;
	}
}
int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

int	draw_map(t_data *img,t_node *var)
{
	int		i;
	int		j;
	int		n;
	int		k;

	n = 0;
	k = 0;
	i = ft_strlen(img->map[0]);
	j = var->lenght;
	img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, i * 80, j * 80, "game");
	draw(img);
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 17, 0, destroy, img);
	mlx_loop(img->mlx);
	return (0);
}
void	draw(t_data *img)
{
	t_node *var;

	var = malloc(sizeof(t_node));

	var->n = 0;
	while(img->map[var->n])
	{
		var->k = 0;
		while(img->map[var->n][var->k])
		{
			drawing(img->map[var->n][var->k],img,var);
			var->k++;
		}
		var->n++;
	}

}
void	drawing(char map,t_data	*img,t_node *var)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(img->mlx, "./ground.xpm", &(img->img_width), &(img->img_height));
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, var->k * 80, var->n * 80);
	if(map == '1')
		img->relative_path = "./block.xpm";
	else if(map == '0')
		img->relative_path = "./ground.xpm";
	else if(map == 'P')
	{
		if(img->px == 0)
			img->relative_path = "./mario2.xpm";
		if(img->px == -1)
			img->relative_path = "./mario3.xpm";
		else if(img->px == -2)
			img->relative_path = "./mario4.xpm";
		else if(img->px == -3)
			img->relative_path = "./mario5.xpm";
	}
	else if(map == 'C')
		img->relative_path = "./environment.xpm";
	// img->indx++;
	img->img = mlx_xpm_file_to_image(img->mlx, img->relative_path, &(img->img_width), &(img->img_height));
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, var->k * 80, var->n * 80);
}
