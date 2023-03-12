/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:10:20 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 02:22:53 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_rechercher(char *haystack, char *needle, int len)
{
	char	*pt;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			pt = (char *)haystack + i;
			j = 0;
			while (needle[j] == haystack[i + j] && i + j < len)
			{
				if (!needle[j + 1])
					return (pt);
				j++;
			}
			pt = 0;
		}
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	char	*pt;
	int		i;

	i = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (needle[i] == '\0')
		return ((char *)haystack);
	pt = ft_rechercher(haystack, needle, len);
	return (pt);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int				i1;
	int				i2;
	char			*p;
	unsigned int	j;

	i1 = 0;
	i2 = 0;
	j = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(j * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (s1[i1])
	{
		p[i1] = s1[i1];
		i1++;
	}
	while (s2[i2])
	{
		p[i1 + i2] = s2[i2];
		i2++;
	}
	p[i1 + i2] = '\0';
	return (p);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
