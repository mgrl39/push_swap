/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:07:13 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/11 22:07:16 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Create a new node with the given number */
t_stack	*ps_lstnew(int number)
{
	t_stack	*node;

	node = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = number;
	node->index = 0;
	node->next = NULL;
	return (node);
}

/* Counts the number of nodes in the stack */
int	ps_lstsize(t_stack *lst)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/* Iterates the stack and returns the last node */
t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
 * Adds a new node to the front or the back of the list
 * If pos is FRONT, add to the front
 * If pos is BACK, add to the back
 */
void	ps_lstadd(t_stack **lst, t_stack *new, t_pos pos)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (pos == FRONT)
	{
		new->next = *lst;
		*lst = new;
	}
	else if (pos == BACK)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last = ps_lstlast(*lst);
			last->next = new;
		}
	}
}

/* 
 * Frees the stack or the arguments
 * If option is FREE_ARGS, free the arguments
 * If option is FREE_STACK, free the stack
 */
void	ft_free_stack_or_args(t_stack **stack, char **args, t_free_opt option)
{
	int		i;
	t_stack	*tmp;

	if (option == FREE_ARGS && args)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	else if (option == FREE_STACK && stack)
	{
		if (!stack)
			return ;
		while (*stack)
		{
			tmp = *stack;
			*stack = (*stack)->next;
			free(tmp);
		}
	}
}
