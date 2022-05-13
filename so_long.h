#ifndef SO_LONG
# define SO_LONG

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
#include <mlx.h>

typedef struct s_node
{
	int c;
	int e;
	int p;
	int	n;
	int	k;
	int lenght;
	int width;

}	t_node;

typedef struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*relative_path;
	//char	**map;
	int		img_width;
	int		img_height;
}				t_data;


char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
int	    ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int		check_map(char **map,t_node *var);
int		check_lenght(char **map,int i,t_node *var);
int		check_width(char **map, int i);
int		check_middle(char **map);
int		draw_map(char **map,t_node *var);
void 	so_long(char **map,t_node *var);
void	drawing(char map,t_data	*img,t_node *var);
#endif