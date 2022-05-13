#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		str1;
	int		str2;
	int		strr1;

	i = -1;
	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	ret = (char *) malloc(sizeof(char) * (str1 + str2 + 1));
	if (!ret)
	{
		free (ret);
		return (NULL);
	}
	if (s1)
		while (s1[++i])
			ret[i] = s1[i];
	strr1 = str1;
	i = 0;
	while (s2[i])
		ret[str1++] = s2[i++];
	ret[strr1 + str2] = '\0';
	free(s1);
	return (ret);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*c;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
	{
		c = malloc(1 * sizeof(char));
		if (!c)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	c = (char *)malloc((len + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (s[start] && len > 0)
	{
		c[j++] = s[start++];
		len--;
	}
	c[j] = '\0';
	return (c);
}
