/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:38:37 by oel-berh          #+#    #+#             */
/*   Updated: 2022/05/22 00:22:52 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char	**map, t_node	*var, t_data	*img)
{
	int	n;

	if ((check_width(map, 0)) == -1)
		return (0);
	if ((check_lenght(map, ft_strlen(map[0]), var)) == -1)
		return (0);
	if ((check_width(map, var->lenght - 1)) == -1)
		return (0);
	if ((check_middle(map, var, img)) == -1)
		return (0);
	return (1);
}

int	check_lenght(char **map, int n, t_node *var)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != n)
			return (-1);
		if (map[i][0] != '1' || map[i][n - 1] != '1')
			return (-1);
		i++;
	}
	var->lenght = i;
	return (i);
}

int	check_width(char **map, int i)
{
	int	n;

	n = 2;
	while (map[i][n])
	{
		if (map[i][n] != '1')
			return (-1);
		n++;
	}
	return (n);
}

int	check_middle(char **map, t_node *var, t_data *img)
{
	int	i;
	int	n;

	i = 0;
	img->c = 0;
	var->e = 0;
	var->p = 0;
	while (map[++i])
	{
		n = -1;
		while (map[i][++n])
		{
			if (map[i][n] == 'C')
				img->c += 1;
			else if (map[i][n] == 'E')
				var->e += 1;
			else if (map[i][n] == 'P')
				var->p += 1;
			else if (map [i][n] != '1' && map[i][n] != '0')
				return (-1);
		}
	}
	if (img->c < 1 || var->e < 1 || var->p != 1)
		return (-1);
	return (0);
}

void	search_map(t_data *img, char n)
{
	int	i;
	int	j;

	i = 0;
	while (img->map[i])
	{
		j = 0;
		while (img->map[i][j])
		{
			if (img->map[i][j] == n)
			{
				img->px = j;
				img->py = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
