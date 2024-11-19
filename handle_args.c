/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:42 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/15 13:38:17 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Handles the error message for handle_args function */
int	handle_error(t_stack **stack_a)
{
	ft_putstr_fd("Error\n", 2);
	ft_free_stack_or_args(stack_a, NULL, FREE_STACK);
	exit(EXIT_FAILURE);
}

/* Process the arguments and individual numbers */
int	process_args(char **args, t_stack **stack_a)
{
	int	j;
	int	num;

	check_if_repeated(args);
	j = 0;
	while (args[j])
	{
		if (!ps_atoi(args[j], &num))
			return (ft_free_stack_or_args(stack_a, args, FREE_ARGS), 0);
		if (!push_to_stack(stack_a, num))
			return (ft_free_stack_or_args(stack_a, args, FREE_ARGS), 0);
		j++;
	}
	return (1);
}

/* 
 * Checks the arguments and processes them 
 * Checks if the arguments are only spaces and checks
 * Returns 1 if the arguments were processed successfully
 * Returns 0 if the arguments were not processed successfully
 */
int	handle_args(int argc, char *argv[], t_stack **stack_a)
{
	int		i;
	char	**args;

	i = 1;
	while (i < argc)
	{
		if (!is_only_spaces(argv[i]))
			return (handle_error(stack_a));
		args = ft_split(argv[i], ' ');
		if (!process_args(args, stack_a))
			return (0);
		ft_free_stack_or_args(stack_a, args, FREE_ARGS);
		i++;
	}
	return (1);
}

/*
 * Checks if the string is only composed of spaces
 * Returns 0 if the string is only composed of spaces
 * Returns 1 if the string is not only composed of spaces
 */
int	is_only_spaces(char *str)
{
	int	i;

	if (!str || ft_strlen(str) == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_ischar(str[i], SPACE))
			return (1);
		i++;
	}
	return (0);
}

/* 
 * This function pushes a value to the stack
 * Returns 1 if the value was pushed successfully
 * Returns 0 if the value was not pushed successfully
 */
int	push_to_stack(t_stack **stack, int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	ps_lstadd(stack, new_node, BACK);
	return (1);
}
