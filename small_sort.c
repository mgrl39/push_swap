/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:08:14 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/16 22:20:17 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
 * This function checks all possible cases:
 * 1, 3, 2
 * 2, 1, 3
 * 2, 3, 1
 * 3, 2, 1
 * 3, 1, 2
 */
void	sort_three(t_stack **a)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = (*a)->value;
	v2 = (*a)->next->value;
	v3 = (*a)->next->next->value;
	if ((v1 < v2 && v1 < v3) && (v2 > v3))
	{
		sa(a);
		ra(a);
	}
	else if ((v1 > v2 && v1 < v3) && (v2 < v3))
		sa(a);
	else if ((v1 < v2 && v1 > v3) && (v2 > v3))
		rra(a);
	else if ((v1 > v2 && v1 > v3) && (v2 > v3))
	{
		sa(a);
		rra(a);
	}
	else if ((v1 > v2 && v1 > v3) && (v2 < v3))
		ra(a);
}

/* This function uses a loop to find the min value of the stack */
int	find_min_value(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

/* 
 * Calcs the number of rotations needed to bring the min element to the top.
 * Returns rotation count and rotation direction (1 for ra, -1 for rra).
 * If the rotation count is less than half of size, returns the rotation count.
 * If the rotation count is more than half of size, returns the negative count.
 */
int	calc_rotations(t_stack *stack, int min_value, int size)
{
	int		rotations;
	t_stack	*current;

	rotations = 0;
	current = stack;
	while (current && current->value != min_value)
	{
		rotations++;
		current = current->next;
	}
	if (rotations <= size / 2)
		return (rotations);
	return (-(size - rotations));
}

/*
 * This function sorts 4 numbers.
 * It finds the min value of the stack and counts how many rotations we need.
 * We push the min value to the stack b.
 * We sort the remaining 3 numbers.
 * We push the min value back to the stack a.
 */
void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	rotations;

	min = find_min_value(*a);
	rotations = calc_rotations(*a, min, 4);
	while (rotations > 0 && rotations--)
		ra(a);
	while (rotations < 0 && rotations++)
		rra(a);
	ps_push(a, b, TO_B);
	sort_three(a);
	ps_push(b, a, TO_A);
}

/* Sorts a stack of 5 elements */
void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	rotations;

	min = find_min_value(*a);
	rotations = calc_rotations(*a, min, 5);
	while (rotations > 0 && rotations--)
		ra(a);
	while (rotations < 0 && rotations++)
		rra(a);
	ps_push(a, b, TO_B);
	sort_four(a, b);
	ps_push(b, a, TO_A);
}
