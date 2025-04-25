/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_children_and_parsing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:11:03 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/14 20:24:30 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_first_child(char **argv, char ***cmds, int pipefd[2], char **envp)
{
	int	file_fd;

	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
	{
		perror(argv[1]);
		return (0);
	}
	dup2(file_fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	if (!find_path_and_exec(cmds[0], envp))
		return (0);
	return (1);
}

int	init_child2(char **argv, char ***cmds, int pipefd[2], char **envp)
{
	int	file_fd;

	file_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_fd == -1)
	{
		perror(argv[4]);
		return (0);
	}
	dup2(pipefd[0], STDIN_FILENO);
	dup2(file_fd, STDOUT_FILENO);
	close(pipefd[1]);
	if (!find_path_and_exec(cmds[1], envp))
		return (0);
	return (1);
}

char	***parse_all_cmds(int argc, char **argv)
{
	int		i;
	int		j;
	int		total_cmds;
	char	***cmds;

	i = 2;
	j = 0;
	total_cmds = argc - 3;
	cmds = malloc(sizeof(char **) * (total_cmds + 1));
	if (!cmds)
		return (NULL);
	while (i < argc - 1)
		cmds[j++] = ft_split(argv[i++], ' ');
	cmds[j] = NULL;
	return (cmds);
}
