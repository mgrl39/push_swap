/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:52 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/14 14:14:23 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc > 1)
	{
		stack_a = NULL;
		if (!handle_args(argc, argv, &stack_a))
		{
			ft_free_stack_or_args(&stack_a, NULL, FREE_STACK);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		check_duplicates(&stack_a);
		check_if_sorted(&stack_a);
		index_stack(&stack_a);
		stack_b = NULL;
		choose_sort_algorithm(&stack_a, &stack_b);
		ft_free_stack_or_args(&stack_a, NULL, FREE_STACK);
		ft_free_stack_or_args(&stack_b, NULL, FREE_STACK);
	}
	return (0);
}

/* 
 * Check if the stack has any duplicates
 * If there are duplicates, print "Error" and exit
 */
void	check_duplicates(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*checker;

	current = *stack_a;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
			{
				ft_free_stack_or_args(stack_a, NULL, FREE_STACK);
				ft_putstr_fd("Error\n", 2);
				exit(EXIT_FAILURE);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

/* Check if the stack is sorted */
void	check_if_sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (!tmp)
		return ;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return ;
		tmp = tmp->next;
	}
	ft_free_stack_or_args(stack_a, NULL, FREE_STACK);
	exit(EXIT_FAILURE);
}
