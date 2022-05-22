/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-berh <oel-berh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:33:50 by oel-berh          #+#    #+#             */
/*   Updated: 2022/05/22 00:41:18 by oel-berh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_node
{
	int	c;
	int	e;
	int	p;
	int	n;
	int	k;
	int	lenght;
	int	width;
}	t_node;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	char	*relative_path2;
	char	**map;
	int		img_width;
	int		img_height;
	int		px;
	int		py;
	int		c;
	int		indx;
	int		fd;
	t_node	*noll;
}				t_data;

char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putstr(char *s);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		check_map(char **map, t_node *var, t_data *img);
int		check_lenght(char **map, int i, t_node *var);
int		check_width(char **map, int i);
int		check_middle(char **map, t_node *var, t_data *img);
int		draw_map(t_data *img, t_node *var);
void	so_long(t_data *img, t_node *var);
void	drawing(char map, t_data	*img, t_node *var);
void	search_map(t_data *img, char n);
void	draw(t_data *img);
void	moves1(int keycode, t_data *img);
void	moves2(int keycode, t_data *img);
void	moves3(t_data *img, int py, int px);
int		key_hook(int keycode, t_data *img);
int		destroy(t_data *data);
#endif