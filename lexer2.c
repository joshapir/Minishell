#include "minishell.h"


int skip (char *str, int i)
{
	while ((str[i]) && (str[i] == ' '))
                i++;
	return (i);
}
/*
void add_token(t_token *lst, char c)
{
	token_type type;

}
	*/

t_token	*handle_quote(char *str, int *i, t_token **current)
{
	char *arr;
	char c;
	token_type type;
	int flag;
	int j;

	flag = 0;
	j = 0;
	c = str[*i];
	type = find_token_type(&str[*i]);
	if (type == TOKEN_QUOTE_DOUBLE)
			flag = 1;
	*i++;
	if (!str[*i])
		printf("Error: no closing quote\n");	
	while ((str[*i]) && str[*i] != c)
	{
			arr[j] = str[*i];
			*i++;
			j++;
	}
	arr[j] = '\0';
	(*current) -> next = new_token(TOKEN_WORD, ft_strdup(arr), 1);
	*current = (*current)->next;
	return(*current);
}

t_token *add_word(char *str, t_token **current, int *i)
{
	int j;
	char *arr;

	j = *i;
	arr = NULL;
	while ((str[j]) && !is_token(str[j]) && str[j] != ' ')
				j++;
	arr = malloc(sizeof(char) * (j + 1));
	if (!arr)
		exit(EXIT_FAILURE);
	j = 0;
	while ((str[*i]) && !is_token(str[*i]) && str[*i] != ' ')
			arr[j++] = str[(*i)++];
	arr[j] = '\0';
	printf("arr = %s\n", arr);
	(*current)->next = new_token(TOKEN_WORD, arr, 0);
	printf("current = %s\n", (*current)->value);
	*current = (*current)->next;
	free(arr);
	return(*current);
}
t_token *lexer (char *str)
{
	int 	i;
	int 	j;
	char	*arr;
	t_token *head;
	t_token *current;
	token_type type;

	i = 0;
	j = 0;
	head = NULL;
	while (str[i])
	{
		i = skip(str, i);
		printf("i = %d\n");
		if (is_token(str[i]))
		{
			type = find_token_type(&str[i]);
			if (type == TOKEN_QUOTE_SINGLE || type == TOKEN_QUOTE_DOUBLE)
			{
                        current = handle_quote(str, &i, &current);
						if (!head)
							head = current;
			}
			else if (!head)
			{
				type = find_token_type(&str[i]);
				head = new_token(type, &str[i], 0);
				current = head;
			}
			else
			{
				current->next = new_token(type, &str[i], 0);
				current = current-> next;
			}
			i++;
		}
		i = skip(str, i);
		printf("i = %d\n");
		if(!is_token(str[i]))
			current = add_word(str, &current, &i);
		if (!head)
			head = current;
	}
	return(head);
}
