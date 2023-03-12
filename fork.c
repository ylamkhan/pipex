/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:33:08 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 02:23:19 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	fork_1(t_data *arg, char **path, int in, int *pi)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		in = open(arg->infile, O_RDONLY);
		if (in == -1)
			ft_error_msg("error in open !");
		if (arg->cmd1[0][0] == ' ' || !get_command(path, arg->cmd1[0]))
			cmd_not_found(arg->av, 2);
		dup2(pi[1], 1);
		dup2(in, 0);
		close(pi[0]);
		close(pi[1]);
		close(in);
		execve(get_command(path, arg->cmd1[0]), arg->cmd1, arg->env);
		ft_error("execve");
	}
	else if (id == -1)
		ft_error("fork");
	return (id);
}

int	fork_2(t_data *arg, char **path, int out, int *pi)
{
	int	id;

	id = fork();
	if (id == 0)
	{
		out = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (out == -1)
			ft_error("open");
		if (arg->cmd2[0][0] == ' ' || !get_command(path, arg->cmd2[0]))
			cmd_not_found(arg->av, 3);
		dup2(pi[0], 0);
		dup2(out, 1);
		close(pi[0]);
		close(pi[1]);
		close(out);
		execve(get_command(path, arg->cmd2[0]), arg->cmd2, arg->env);
		ft_error("execve");
	}
	else if (id == -1)
		ft_error("fork");
	return (id);
}

void	cmd_not_found(char **av, int i)
{
	ft_error_msg("command not found: ");
	ft_error_msg(av[i]);
	write(1, "/n", 1);
	exit(EXIT_FAILURE);
}
