/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:02:17 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 02:20:51 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	perror(s);
	exit(0);
}

void	ft_error_msg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
	write(1, "\n", 1);
	exit(1);
}

t_data	*init_data(char **av, char **env)
{
	t_data	*arg;

	arg = malloc(sizeof(t_data));
	if (!arg)
		return (0);
	arg->infile = ft_strdup(av[1]);
	arg->outfile = ft_strdup(av[4]);
	arg->cmd1 = ft_split(av[2], ' ');
	arg->cmd2 = ft_split(av[3], ' ');
	arg->env = env;
	arg->av = av;
	return (arg);
}

int	main(int ac, char **av, char **env)
{
	t_data	*arg;
	char	**path;

	if (ac != 5)
		ft_error_msg("ERROR ARGS !!\n EXEMPLE :\n./pipex file1 cmd1 cmd2 file2");
	arg = init_data(av, env);
	path = get_path(env);
	pipex(arg, path);
	//main_free(path, arg);
	return (0);
}
