/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:11:32 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/20 20:25:15 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void
	redirect(int pipefd[], char *argv[], char *envp[])
{
	int		infile_fd;
	char	**cmd_args;
	char	*path;

	close(pipefd[READ_END]);
	infile_fd = get_fd(argv);
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipefd[WRITE_END], STDOUT_FILENO);
	close(pipefd[WRITE_END]);
	cmd_args = get_cmd_args(argv[2]);
	path = get_path(cmd_args[0], envp);
	check_execve(envp, cmd_args, path);
	free(cmd_args);
	exit(errno);
}

void
	exec(int pipefd[], char *argv[], char *envp[])
{
	int		outfile_fd;
	char	**cmd_args;
	char	*path;

	outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 00744);
	check_fd(argv[4], outfile_fd);
	dup2(pipefd[READ_END], STDIN_FILENO);
	close(pipefd[READ_END]);
	dup2(outfile_fd, STDOUT_FILENO);
	cmd_args = get_cmd_args(argv[3]);
	path = get_path(cmd_args[0], envp);
	check_execve(envp, cmd_args, path);
	free(cmd_args);
	exit(errno);
}

pid_t
	get_pid(pid_t pid)
{
	pid = fork();
	if (pid == -1)
		ft_error_exit("Fork failed", errno);
	return (pid);
}

int
	main(int argc, char *argv[], char *envp[])
{
	int		pipefd[2];
	int		piperv;
	int		status;
	pid_t	pid;

	check_argc(argc);
	piperv = pipe(pipefd);
	if (piperv == -1)
		ft_error_exit("Error creating pipe", errno);
	pid = 0;
	pid = get_pid(pid);
	if (pid == 0)
		redirect(pipefd, argv, envp);
	else
	{
		close(pipefd[WRITE_END]);
		pid = get_pid(pid);
		if (pid == 0)
			exec(pipefd, argv, envp);
		else
			close(pipefd[READ_END]);
	}
	wait(&status);
	wait(&status);
	return (0);
}
