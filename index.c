/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:07 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/16 22:19:35 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_array(t_stack *stack, int size)
{
	int	*array;
	int	i;

	array = malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i++] = stack->value;
		stack = stack->next;
	}
	return (array);
}

void	bubble_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	swapped;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

/* Assigns indexes to the stack using the sorted array */
void	assign_index(t_stack *stack, int *sorted_array, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == sorted_array[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

/* 
 * Checks the size of the stack and creates an array of integers 
 * Sorts the array using bubble sort, then assigns the indexes to the stack 
 */
void	index_stack(t_stack **a)
{
	int	size;
	int	*array;

	size = ps_lstsize(*a);
	array = stack_to_array(*a, size);
	if (!array)
		return ;
	bubble_sort_array(array, size);
	assign_index(*a, array, size);
	free(array);
}
