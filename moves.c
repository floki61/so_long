#include "so_long.h"

void    moves2(t_data *img,int py, int px)
{
        img->map[img->py][img->px] = '0';
	    img->map[py][px] = 'P';
        draw(img);
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
		img->relative_path = "./mario3.xpm";
        moves2(img,py, px - 1);
	}
	else if (keycode == 13 && img->map[py - 1][px] != '1')
	{
		img->relative_path = "./mario5.xpm";
        moves2(img,py - 1, px);
	}
	else if (keycode == 1 && img->map[py + 1][px] != '1')
	{
		img->relative_path = "./mario2.xpm";
        moves2(img,py + 1, px);
	}
	else if (keycode == 2 && img->map[py][px + 1] != '1')
	{
		img->relative_path = "./mario4.xpm";
        moves2(img,py, px + 1);
	}
}