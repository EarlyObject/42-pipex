/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 16:38:14 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/20 20:23:38 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	check_argc(int argc)
{
	if (argc != 5)
		ft_error_exit("Check arguments: ./pipex file1 cmd1 cmd2 file2", 1);
}

void
	check_fd(char *name, int fd)
{
	if (fd == -1)
	{
		ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(name, 2);
		exit(errno);
	}
}

int
	get_fd(char *argv[])
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	check_fd(argv[1], fd);
	return (fd);
}

void
	check_execve(char *envp[], char **cmd_args, const char *path)
{
	if (execve(path, cmd_args, envp) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd_args[0], 2);
	}
}
