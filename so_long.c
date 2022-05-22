/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 23:04:04 by oel-berh          #+#    #+#             */
/*   Updated: 2022/05/21 23:04:18 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_data *img, t_node *var)
{
	char	*instruction;
	char	*tab;

	instruction = get_next_line(img->fd);
	if (!instruction)
	{
		write(1, "Error\n", 6);
		exit (0);
	}
	while (instruction)
	{
		tab = ft_strjoin(tab, instruction);
		instruction = get_next_line(img->fd);
	}
	img->map = ft_split(tab, '\n');
	if (!check_map(img->map, var, img))
	{
		write (1, "Error\n", 6);
		exit (0);
	}
	draw_map(img, var);
}

int	main(int argc, char **argv)
{
	t_data	*img;
	t_node	*var;

	img = malloc(sizeof(t_data));
	var = malloc(sizeof(t_node));
	img->fd = open(argv[1], O_RDONLY);
	if (!(img->fd))
		write(1, "Error\n", 6);
	so_long (img, var);
}
