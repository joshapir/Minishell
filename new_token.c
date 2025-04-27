#include "minishell.h"


void split_token(char *str)
{
	int i;
	char *arr;

	i = 0;

	while(str[i])
	{
		if(is_token(str[i]))
			break ;
		i++;
	}
	

}
t_token *new_token(token_type type, char *value, int flag)
{
    t_token *token = malloc(sizeof(t_token));
   // if (type == TOKEN_INVALID || value == NULL)
   // {
	//    token->type = TOKEN_INVALID;
	 //   token->value = NULL;
	 //   token->next = NULL;
	 //   return(token);
//    }
    token->type = type;
    token->value = ft_strdup(value);
	token->inside_quotes = flag;
    token->next = NULL;
    return (token);
}
