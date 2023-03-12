/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:31:51 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 01:45:22 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	copy = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static int	count_word(char *s, char c)
{
	int	i;
	int	len;
	int	a;

	i = 0;
	len = 0;
	a = 1;
	while (s[i])
	{
		if (s[i] != c && a)
		{
			a = 0;
			len++;
		}
		if (s[i] == c)
			a = 1;
		i++;
	}
	return (len);
}

static int	ft_lencount(char *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[*i])
	{
		if (s[*i] == c)
		{
			break ;
		}
		(*i)++;
		len++;
	}
	return (len);
}

static void	*freemove(char ***ptr, int d)
{
	int		i;
	char	**a;

	a = *ptr;
	i = 0;
	if (!a[d])
	{
		while (d >= 0)
		{
			free(a[d]);
			d--;
		}
		free(a);
		return (0);
	}
	return ((void *)1);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		d;
	char	**ptr;

	i = 0;
	d = 0;
	if (!s)
		return (NULL);
	ptr = malloc((count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		ptr[d] = ft_substr(s, i, ft_lencount(s, c, &i));
		if (!freemove(&ptr, d))
			return (NULL);
		d++;
	}
	ptr[d] = NULL;
	return (ptr);
}
