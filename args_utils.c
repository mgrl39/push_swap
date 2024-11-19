/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:06:44 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/13 15:13:36 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 * Check if the character is a digit, space or symbol
 * Returns 1 if it is
 * Returns 0 if it is not
 * If the type is DIGIT, it checks if the character is a digit
 * If the type is SPACE, it checks if the character is a space
 * If the type is SYMBOL, it checks if the character is a symbol
 */
int	ft_ischar(int c, t_char_type type)
{
	if (type == DIGIT)
		return (c >= '0' && c <= '9');
	else if (type == SPACE)
		return (c == 32 || (c >= 9 && c <= 13));
	else if (type == SYMBOL)
		return (c == '-' || c == '+');
	return (0);
}

/* 
 * Converts a string to an integer
 * If the number is out of the range of an int, returns 0
 * If the conversion was successful, returns 1
 */
int	ps_atoi(const char *str, int *result)
{
	int			i;
	int			sign;
	long long	num;

	sign = 1;
	num = 0;
	i = 0;
	while (ft_ischar(str[i], SPACE))
		i++;
	if (ft_ischar(str[i], SYMBOL))
		if (str[i++] == '-')
			sign = -1;
	if (ft_ischar(str[i], DIGIT) == 0)
		return (0);
	while (str[i] && ft_ischar(str[i], DIGIT))
	{
		num = num * 10 + (str[i] - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
			return (0);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	*result = (int)(num * sign);
	return (1);
}

/*
 * Check if the strings are the same
 * Returns 0 if they are the same
 * Returns the difference between the first different character
 */
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/*
 * Compare the arguments to check if there are any repeated
 * If there are repeated arguments, print "Error" and exit
 */
void	check_if_repeated(char **argv)
{
	int	i;
	int	j;

	if (!argv)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[j] != NULL)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0 && i != j)
			{
				ft_putstr_fd("Error\n", 2);
				ft_free_stack_or_args(NULL, argv, FREE_ARGS);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

/* Print the string */
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
