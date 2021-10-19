/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:53:52 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/20 18:06:30 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char
	**get_paths_arr(char *envp[])
{
	char	**paths_arr;
	int		i;

	i = 0;
	if (!envp || !envp[i])
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	paths_arr = ft_split(envp[i] + 5, ':');
	return (paths_arr);
}

char
	*get_bin(const char *cmd, char **paths_arr, int i)
{
	char	*bin;
	char	*dir;

	dir = ft_strjoin(paths_arr[i], "/");
	bin = ft_strjoin(dir, cmd);
	free(dir);
	return (bin);
}

char
	*get_path(char *cmd, char *envp[])
{
	char	**paths_arr;
	char	*bin;
	int		i;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	paths_arr = get_paths_arr(envp);
	if (!paths_arr)
		ft_error_exit("Environment variable absent", 0);
	i = 0;
	while (paths_arr[i])
	{
		bin = get_bin(cmd, paths_arr, i);
		if (!access(bin, F_OK))
		{
			free(paths_arr);
			return (bin);
		}
		free(bin);
		i++;
	}
	free(paths_arr);
	return (cmd);
}

char
	**get_cmd_args(char *cmds)
{
	char	**cmd_args;

	cmd_args = ft_split(cmds, ' ');
	return (cmd_args);
}
