#include "so_long.h"

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
		exit(0);
	// else if (keycode == 13)
	// {
	// 	mlx_clear_window(img->mlx, img->mlx_win);

	// }
	return (0);
}

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}



int	draw_map(char **map,t_node *var)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	int		i;
	int		j;
	int		n;
	int		k;

	n = 0;
	k = 0;
	//img->map = NULL;
	i = ft_strlen(*map);
	j = var->lenght;
	img = malloc(sizeof(t_data));
	img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, i * 100, j * 100, "game");
	var->n = 0;
	while(map[var->n])
	{
		var->k = 0;
		while(map[var->n][var->k])
		{
			drawing(map[var->n][var->k],img,var);
			var->k++;
		}
		var->n++;
	}
	//img->map = map;
	mlx_key_hook(img->mlx_win, key_hook, img);
	mlx_hook(img->mlx_win, 17, 0, destroy, img);
	mlx_loop(img->mlx);
	return (0);
}
void	drawing(char map,t_data	*img,t_node *var)
{
	int	width;
	int	height;

	if(map == '1')
	{
		img->relative_path = "./gg.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->relative_path, &(img->img_width), &(img->img_width));
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, var->k * 100, var->n * 100);
	}
	// else if(map == '0')
	// {
	// 	img->relative_path = "./bleu.xpm";
	// 	img->img = mlx_xpm_file_to_image(img->mlx, img->relative_path, &(img->img_width), &(img->img_width));
	// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, var->k * 100, var->n * 100);
	// }
	else if(map == 'P')
	{
		img->relative_path = "./player.xpm";
		img->img = mlx_xpm_file_to_image(img->mlx, img->relative_path, &(img->img_width), &(img->img_width));
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, var->k * 100, var->n * 100);
	}
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

//     img.relative_path = "./img1.xpm";
// 	mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1900, 100, "game");
//     img.img = mlx_xpm_file_to_image(mlx, img.relative_path, &img.img_width, &img.img_height);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }
