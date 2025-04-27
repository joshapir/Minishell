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
char *add_quoted_word(char *str, int i, int type)
{
	int j;
	char quote;
	char *arr;
	t_token *current;
	
	arr = NULL;
	i++;
	j = i;
	if (type == TOKEN_QUOTE_SINGLE)
		quote = '\'';
	else
		quote = '"';
	while ((str[j + 1]) && str[j + 1] != quote)
				j++;
	arr = malloc(sizeof(char) * (j + 1));
	if (!arr)
		exit(EXIT_FAILURE);
	j = 0;
	while ((str[i]) && str[i] != quote)
	{
		("qchar = %c\n", str[i]);
			arr[j] = str[i];
			i++;
			j++;
	}
	arr[j] = '\0';
	return(arr);
}
t_token	*handle_quote(char *str, int *i)
{
	char *arr;
	char c;
	int type;
	t_token *current;
	int flag;
	int j;

	arr = NULL;
	flag = 0;
	j = 0;
	c = str[*i];
	("c = %c\n", c);
	type = find_token_type(&str[*i]);
	if (type == TOKEN_QUOTE_DOUBLE)
			flag = 1;
	*i++;
	if (!str[*i])
	{
		("Error: no closing quote\n");
		exit(EXIT_FAILURE);
	}	
	j = *i;
	arr = add_quoted_word(str, j , type);
	("word = %s\n", arr);
	current = new_token(TOKEN_WORD, arr, 1);
	free(arr);
	//*current = (*current)->next;
	return(current);
}

t_token *add_word(char *str, int *i)
{
	int j;
	char *arr;
	t_token *current;

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
	//printf("arr = %s\n", arr);
	current = new_token(TOKEN_WORD, arr, 0);
	//printf("current = %s\n", current->value);
	//*current = (*current)->next;
	free(arr);
	return(current);
}
t_token *lexer (char *str)
{
	int 	i;
	int 	j;
	char	*arr;
	t_token *head;
	t_token *current;
	int	 type;

	i = 0;
	j = 0;
	head = NULL;
	//current = NULL;
	printf("str = %s\n", str);
	while (str[i])
	{
		//if(!head)
		//	head = current;
		// if (current)
		//	current = current->next;
		i = skip(str, i);
		printf("i = %d\n");
		("str[i] = %c\n", str[i]);
		if (is_token(str[i]))
		{
			write(1, "here\n", 5);
			type = find_token_type(&str[i]);
			("type = %d\n", type);
			if (type == TOKEN_QUOTE_SINGLE || type == TOKEN_QUOTE_DOUBLE)
			{
				write(1, "here2\n", 6);
				if (!head)
				{
					head = handle_quote(str, &i);
					current = head;
				}
				else
				{
					current->next = handle_quote(str, &i);
					current = current->next;
				}
						
						//("current = %s\n", current->value);
							
						
					//("head = %p\n", head->value);
			}
		//	else if (!head)
		//	{
		//		type = find_token_type(&str[i]);
		//		head = new_token(type, &str[i], 0);
				//current = head;
		//		current = head->next;
		//	}
			else
			{
				printf("current before adding token %s\n", current->value);
				if (!head)
				{
					head = new_token(type, &str[i], 0);
					current = head;
				}
				else
				{
					current->next = new_token(type, &str[i], 0);
					current = current->next;
				}
				
				printf("token %s\n", current->value);
				//current = current-> next;
			}
			i++;
			//write(1, "hello\n", 6);
		}
		printf("loop\n");
		i = skip(str, i);
		printf("i at bottom = %d\n");
		printf("str[i] at bottom = %c\n", str[i]);
		if((str[i]) && !is_token(str[i]))
		{
			printf("not a token\n");
				if (!head)
				{
					head = add_word(str, &i);
					current = head;
				}
			else
			{	
				current->next = add_word(str, &i);
				current = current->next;
			}
			printf("here\n");
			//printf("current EOL = %s\n", current->value);
			
				
					
			//current = current->next;
		}
		printf("after\n");
		//printf("current EOL = %s\n", current->value);
	//	if (!head)
		//	head = current;
		//printf("head: %s\n", head->value);
		//if(current->next)
		//	current = current->next;
	}
	//printf("head: %s\n", head->next->next->value);
	return(head);
}
