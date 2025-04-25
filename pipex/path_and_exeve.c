/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_and_exeve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:07:41 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/14 20:10:14 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_loop(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (paths[i])
	{
		path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!path)
			return (0);
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (free(path), NULL);
		free(path);
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!path)
			return (0);
		if (access(path, X_OK) == 0)
			return (free_split(paths), path);
		free(path);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (!*envp)
		return (NULL);
	paths = ft_split(*envp + 5, ':');
	path = path_loop(paths, cmd);
	if (!path)
	{
		free_split(paths);
		return (0);
	}
	else
		return (path);
	free_split(paths);
	return (NULL);
}

int	find_path_and_exec(char **cmds, char **envp)
{
	char	*path;

	path = get_path(cmds[0], envp);
	if (!path)
	{
		return (0);
	}
	if (execve(path, cmds, envp) == -1)
	{
		free(path);
		return (0);
	}
	free(path);
	return (1);
}
