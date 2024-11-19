/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:28 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/16 22:20:11 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 * This function sorts the stack using different sorting "algorithms".
 * Radix sort is only used when the stack has more than 5 numbers.
 */
void	choose_sort_algorithm(t_stack **a, t_stack **b)
{
	int	size;

	if (!a || !*a)
		return ;
	size = ps_lstsize(*a);
	if (size == 2 && ((*a)->value > (*a)->next->value))
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

/* 
 * This function calculates the maximum number of bits needed to represent
 * the maximum index in the stack, necessary for Radix Sort.
 */
int	get_max_bits(t_stack *stack)
{
	int	max;
	int	max_bits;

	max = stack->index;
	max_bits = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/*
 * This function sorts the stack using Radix Sort.
 * This uses the bitwise operation to sort the stack.
 * It finds the maximum number of bits needed to represent the maximum index.
 * It pushes the numbers to the stack b if the bit is 1.
 * It then pushes the numbers back to the stack a.
 * It repeats this process until all the numbers are sorted.
 */
void	radix_sort(t_stack **a, t_stack **b)
{
	int		max_bits;
	int		j;
	int		i;
	int		size;
	t_stack	*current;

	i = 0;
	size = ps_lstsize(*a);
	max_bits = get_max_bits(*a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current = *a;
			if (((current->index >> i) & 1) == 1)
				ra(a);
			else
				ps_push(a, b, TO_B);
			j++;
		}
		while (ps_lstsize(*b) > 0)
			ps_push(b, a, TO_A);
		i++;
	}
}
