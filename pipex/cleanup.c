/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:47:09 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/14 19:48:42 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_and_exit(char ****cmds, char *cmd)
{
	perror(cmd);
	free_cmds(*cmds);
	exit(127);
}

void	free_and_close(int pipefd[1], char ****cmds)
{
	close(pipefd[0]);
	close(pipefd[1]);
	free_cmds(*cmds);
}

void	free_cmds(char ***cmds)
{
	int	i;

	i = 0;
	if (!cmds)
		return ;
	while (cmds[i])
	{
		free_split(cmds[i]);
		i++;
	}
	free(cmds);
}

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
