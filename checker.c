#include "so_long.h"

int	check_map(char **map,t_node *var)
{
   int  n;

   if((n = check_width(map,0)) == -1)
		return (0);
   if ((n = check_lenght(map,n,var)) == -1)
		return (0);
	if((n = check_width(map,n - 1)) == -1)
		return (0);
	if((n = check_middle(map)) == -1)
		return (0);
	return (1);
}

int	check_lenght(char **map,int n,t_node *var)
{
	int i;

	i = 0;
	while(map[i])
	{
		if(ft_strlen(map[i]) != n)
		{
			printf("line lenght\n");
			return(-1);
		}
		if (map[i][0] != '1' || map[i][n - 1] != '1')
		{
			printf("lenght\n");
			return (-1);
		}
		i++;
	}
	var->lenght = i;
	return (i);
}

int	check_width(char **map, int i)
{
	int	n;

	n = 2;
	while(map[i][n])
	{
		if(map[i][n] != '1')
		{
			printf("%d.%d != 1\n",i,n);
			return (-1);
		}
		n++;
	}
	return(n);
}

int	check_middle(char **map)
{
	int i;
	int n;
	t_node var;

	i = 0;
	var.c = 0;
	var.e = 0;
	var.p = 0;
	while(map[++i])
	{
		n = -1;
		while(map[i][++n])
		{
			if(map[i][n] == 'C')
				var.c += 1;
			else if(map[i][n] == 'E')
				var.e += 1;
			else if(map[i][n] == 'P')
				var.p += 1;
			else if(map [i][n] != '1' && map[i][n] != '0')
			{
				printf("middle\n");
				return (-1);
			}
		}
	}
	if(var.c < 1 || var.e < 1 || var.p != 1)
		return (-1);
	return (0);
}
void so_long(char **map,t_node *var)
{
	draw_map(map,var);
}

int main()
{
	char *instruction;
	char *tab;
	char **map;
	int fd;
	int i;
	t_node *var;
	
	i = 0;
	var = malloc(sizeof(t_node));
	fd = open("map.ber", O_RDONLY);
	instruction = get_next_line(fd);
	if(!instruction)
	{
		printf("Eroor2\n");
		exit (0);
	}
	while (instruction)
	{
		tab = ft_strjoin(tab,instruction);
		instruction = get_next_line(fd);
	}
	map = ft_split(tab, '\n');
	if (!check_map(map,var))
	{
		printf("error\n");
		exit (0);
	}
	so_long(map,var);
}
