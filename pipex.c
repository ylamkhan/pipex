/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:25:18 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 02:18:55 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	int		i;
	char	**path;
	char	*a;

	i = 0;
	if (!env[i])
	{
		write(1, "error !\n", 8);
		exit(0);
	}
	while (!ft_strnstr(env[i], "PATH", 4))
		i++;
	path = ft_split(env[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		a = path[i];
		path[i++] = ft_strjoin(a, "/");
		free(a);
	}
	return (path);
}

char	*get_command(char **path, char *cmd)
{
	int		i;
	char	*a;

	if (access(cmd, X_OK) != -1)
		return (cmd);
	if (!ft_strncmp(cmd, "/", 1))
	{
		write(1, "error !/n", 8);
		exit(0);
	}
	i = 0;
	while (path[i])
	{
		a = ft_strjoin(path[i], cmd);
		if (!access(a, X_OK))
		{
			free(a);
			return (ft_strjoin(path[i], cmd));
		}
		free(a);
		i++;
	}
	return (0);
}

void	pipex(t_data *arg, char **path)
{
	int	pi[2];
	int	fd[2];
	int	in;
	int	out;

	in = 0;
	out = 0;
	pipe(fd);
	if (pipe(pi) < 0)
		ft_error("pipe");
	fd[0] = fork_1(arg, path, in, pi);
	fd[1] = fork_2(arg, path, out, pi);
	close(pi[1]);
	close(pi[0]);
	waitpid(fd[0], 0, 0);
	waitpid(fd[1], 0, 0);
}
