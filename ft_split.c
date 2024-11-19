/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:06:57 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/14 13:20:07 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* TODO: COMPARE WITH THE ORIGINAL ONE */

/* Count the number of strings in the array */
/* To count the number of strings, we iterate through the string s */
/* If the character is not the separator, we increment the total */
/* We then skip the string until we find the separator */
/* We repeat the process until we reach the end of the string */
static size_t	ft_array_len(char const *s, char c)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			total++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (total);
}

/* Allocate memory for the string */
/* Copy the substring from the string s to the new string */
/* Return the new string */
static char	*ft_next_string(char const *s, char c, size_t *start)
{
	size_t	i;
	size_t	length;
	char	*str;

	i = *start;
	while (s[i] != '\0' && s[i] == c)
		i++;
	*start = i;
	length = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		length++;
		i++;
	}
	str = ft_substr(s, *start, length);
	*start = i;
	return (str);
}

/* If the allocation fails, free the memory allocated for the strings */
static void	ft_free_memory(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

/* Split the string s using the character c as separator */
/* If the string s is NULL, return NULL */
/* Count the number of strings in the array */
/* Allocate memory for the array of strings, if the alloc fails, return NULL */
/* Iterate through the string s */
char	**ft_split(char const *s, char c)
{
	size_t	strcount;
	size_t	i;
	size_t	start;
	char	**result;

	if (!s)
		return (NULL);
	strcount = ft_array_len(s, c);
	result = (char **)malloc((strcount + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < strcount)
	{
		result[i] = ft_next_string(s, c, &start);
		if (!result[i])
			return (ft_free_memory(result), NULL);
		i++;
	}
	result[i] = NULL;
	return (result);
}
