/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:42:27 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/14 20:24:17 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_and_status(pid_t pid1, pid_t pid2, int *status)
{
	waitpid(pid1, &status[0], 0);
	waitpid(pid2, &status[1], 0);
	if (WIFEXITED(status[1]))
	{
		status[2] = WEXITSTATUS(status[1]);
	}
}

int	pipex(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid[2];
	int		status[3];
	char	***cmds;

	if (argc != 5)
		return (write(2, "Error\n", 6), 1);
	cmds = parse_all_cmds(argc, argv);
	if (pipe(pipefd) == -1)
		perror("pipe");
	pid[0] = fork();
	if (pid[0] == -1)
		perror("fork");
	if (pid[0] == 0)
		if (! init_first_child(argv, cmds, pipefd, envp))
			free_and_exit(&cmds, cmds[0][0]);
	pid[1] = fork();
	if (pid[1] == 0)
		if (!init_child2(argv, cmds, pipefd, envp))
			free_and_exit(&cmds, cmds[1][0]);
	free_and_close(pipefd, &cmds);
	wait_and_status(pid[0], pid[1], status);
	exit(status[2]);
	return (0);
}
