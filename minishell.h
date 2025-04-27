#ifndef MINISHELL_H
#define MINISHELL_H

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum
{
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_IN,
    TOKEN_REDIRECT_OUT,
    TOKEN_APPEND,
    TOKEN_HEREDOC,
    TOKEN_SEPARATOR,
    TOKEN_QUOTE_SINGLE,
    TOKEN_QUOTE_DOUBLE,
    TOKEN_VARIABLE,
    TOKEN_INVALID
} token_type;

typedef struct s_token 
{
    token_type type;
    char *value;
    bool inside_quotes;
    struct s_token *next;
} t_token;


char *ft_strdup (char *str);
char **ft_split(char *str);
token_type find_token_type(char *str);
int is_word(char *str);
int is_token(char c);
t_token *new_token(token_type type, char *value, int flag);
t_token *lexer (char *str);
int has_token(char *str);
t_token *lexer (char *str);
char *ft_strdup_char (char c);
#endif
