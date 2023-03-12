/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 00:38:59 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 01:55:47 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*p;
	int		j;

	i = start;
	j = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) - start <= len)
		len = ft_strlen((s + start));
	p = (char *)malloc(len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (j < len && *(s + i + j))
	{
		*(p + j) = *(s + i + j);
		j++;
	}
	*(p + j) = '\0';
	return (p);
}

void	free_tab_2d(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	main_free(char **path, t_data *arg)
{
	free_tab_2d(path);
	free_tab_2d(arg->cmd1);
	free_tab_2d(arg->cmd2);
	free(arg->infile);
	free(arg->outfile);
	free(arg);
}
