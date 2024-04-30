#include "long.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	if (!s1)
		s1 = ft_strdup("");
	len = (ft_strlen(s1) + ft_strlen(s2));
	p = malloc((sizeof(char) * len) + 1);
	if (!p)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		p[len] = s1[len];
		len++;
	}
	while (s2[i])
		p[len++] = s2[i++];
	p[len] = '\0';
	free(s1);
	return (p);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*p;

	len = ft_strlen(s1);
	p = malloc((len * sizeof(char) + 1));
	if (!p)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		p[len] = s1[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((char)c == *s)
			return (s);
		s++;
	}
	if ((char)c == '\0')
		return (s);
	return (NULL);
}
char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	if(!src)
		return(NULL);
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return(dest);
}

int 	ft_strlen(char *s)
{
	int i;

	i=0;
	while(s[i])
		i++;
	return(i);
}
