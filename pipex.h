/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamkhan <ylamkhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:01:55 by ylamkhan          #+#    #+#             */
/*   Updated: 2023/03/12 01:58:04 by ylamkhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct data
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**env;
	char	**av;
}			t_data;

/*libft*/
int			ft_strlen(char *s);
char		*ft_rechercher(char *haystack, char *needle, int len);
char		*ft_strnstr(char *haystack, char *needle, int len);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, int n);
/*libft2*/
char		*ft_strdup(char *s1);
char		**ft_split(char *s, char c);
/*libft3*/
char		*ft_substr(char *s, int start, int len);
void		free_tab_2d(char **av);
void		main_free(char **path, t_data *arg);

/*pipex*/
char		**get_path(char **env);
char		*get_command(char **path, char *cmd);
void		pipex(t_data *arg, char **path);

/*main*/
t_data		*init_data(char **av, char **env);
void		ft_error(char *s);
void		ft_error_msg(char *s);
/*fork*/
int			fork_1(t_data *arg, char **path, int in, int *pi);
int			fork_2(t_data *arg, char **path, int out, int *pi);
void		cmd_not_found(char **av, int i);

#endif
