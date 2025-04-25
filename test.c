#include <stdlib.h>
# include <stdio.h>
//# include <unistd.h>
# include <stddef.h>
# include <sched.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
#include "./pipex/pipex.h"

int	is_pipe(char **args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(args[i])
	{
		while(args[i][j])
		{
			if(args[i][j] == '|')
				return(1);
			j++;
		}
		j = 0;
		i++;
	}
	return(0);
}

//char    *get_path(char *cmd, char **envp);
int main (int argc, char **argv, char **envp)
{
    char    *path;
    char ***cmds = parse_all_cmds(argc, argv);
    char *line;
	int id;
	char **args;
	int pipefd;
	
    while (1)
    {
	//	args = ft_split(line, ' ');
	//	printf("%s\n", cmds[0][0]);
        line = readline("> ");	
		args = ft_split(line, ' ');
		printf("%s\n", args[0]);
		if (is_pipe(args))
		{
		//	pipefd = fork();
		//	if(pipefd == 0)
		//	{
				printf("pipe found:\n");
				pipex(5, args, envp);
				//wait(pipefd);
				printf("after pipex");
				//break ;
		//	}
			line = readline("> ");
			args = ft_split(line, ' ');
		}
		//cmds = parse_all_cmds(2, &line);
        path = get_path(args[0], envp);
		//printf("%s\n", path);
		//find_path_and_exec(cmds[0], envp);
        if (!path)
            return (12);
		id = fork();
		if (id == 0)
        	execve(path, args, envp);
		wait(NULL);
        free(line);
        free(path);
    }
}
