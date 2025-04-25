/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:10:01 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/14 19:49:34 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	ft_skip(char const *s, int i, char c)
{
	while (s[i] == c)
		i++;
	return (i);
}

void	ft_len_assign(char **arr, char const *s, char c, int count)
{
	int	i;
	int	j;
	int	len;
	int	start;

	j = 0;
	i = 0;
	while (count-- > 0)
	{
		i = ft_skip(s, i, c);
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = (i - start);
		arr[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!arr[j])
		{
			while (j-- >= 0)
				free (arr[j]);
			free(arr);
			return ;
		}
		j++;
	}
}

int	ft_word_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		while (s[i] && (i == 0 || s[i - 1] == c))
		{
			count++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

void	ft_loop(char **arr, int count, char const *s, char c)
{
	int	j;
	int	i;
	int	current_word;

	i = 0;
	current_word = 0;
	i = ft_skip(s, i, c);
	j = 0;
	while (current_word < count)
	{
		while (s[i] != c && s[i] != '\0')
			arr[current_word][j++] = s[i++];
		arr[current_word][j] = '\0';
		current_word++;
		j = 0;
		i = ft_skip(s, i, c);
	}
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;

	if (s == NULL || s[0] == '\0')
	{
		arr = (char **)malloc(sizeof(char *) * (1));
		arr[0] = NULL;
		return (arr);
	}
	count = ft_word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	ft_len_assign(arr, s, c, count);
	ft_loop(arr, count, s, c);
	return (arr);
}
/*int main() {
    char *invalidReadCheck = malloc(sizeof(char));
    *invalidReadCheck = '\0';
    
    char **tab = ft_split(invalidReadCheck, 0);
    
    // Use assert for checking
    assert(tab[0] == NULL);
    
    free(invalidReadCheck);
    
    // Free the result of ft_split
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
    
    printf("Test passed successfully.\n");
    
    return 0;
}*/

/*int main (void)
{
    char **result;
    int i;

    result = ft_split(0, 0);
    if (result)
    {
       // printf("Test case 1: Splitting \"Life is good\" by ' '\n");
        for (i = 0; result[i] != NULL; i++)
        {
            printf("result[%d]: %s\n", i, result[i]);
            free(result[i]);
        }
            printf("result[%d]: %s\n", i, result[i]);

        free(result);
    }

    return (0);
}*/
