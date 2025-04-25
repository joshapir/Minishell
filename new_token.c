#include "minishell.h"

t_token *new_token(token_type type, char *value)
{
    t_token *token = malloc(sizeof(t_token));
    if (type == TOKEN_INVALID || value == NULL)
    {
	    token->type = TOKEN_INVALID;
	    token->value = NULL;
	    token->next = NULL;
	    return(token);
    }
    token->type = type;
    token->value = ft_strdup(value);
    token->next = NULL;
    return (token);
}
