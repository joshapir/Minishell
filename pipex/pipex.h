/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:18:17 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/14 20:27:44 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <sched.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

char	***parse_all_cmds(int argc, char **argv);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*path_loop(char **paths, char *cmd);
char	*get_path(char *cmd, char **envp);
void	free_and_close(int pipefd[1], char ****cmds);
void	wait_and_status(pid_t pid1, pid_t pid2, int *status);
void	free_and_exit(char ****cmds, char *cmd);
void	free_cmds(char ***cmds);
void	free_split(char **arr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		find_path_and_exec(char **cmds, char **envp);
int		init_first_child(char **argv, char ***cmds, int pipefd[2], char **envp);
int		init_child2(char **argv, char ***cmds, int pipefd[2], char **envp);
int     pipex(int argc, char **argv, char **envp);
size_t	ft_strlen(const char *s);
#endif
