/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:08:00 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/14 14:04:49 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the first two elements of the stack */
void	sa(t_stack **lst)
{
	t_stack	*tmp;

	if (ps_lstsize(*lst) <= 1)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	ft_putstr_fd("sa\n", 1);
}

/* 
 * Push the first element of the stack to the other stack
 * To push to stack A, use ps_push(&stack_b, &stack_a, TO_A)
 * To push to stack B, use ps_push(&stack_a, &stack_b, TO_B)
 */
void	ps_push(t_stack **src, t_stack **dest, t_push_dir direction)
{
	t_stack	*temp;

	if (!src || !*src)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
	if (direction == TO_A)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}

/* Rotates the stack by moving the first element to the end */
void	ra(t_stack **a)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = ps_lstlast(*a);
	*a = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd("ra\n", 1);
}

/* Rotates the stack by moving the last element to the beginning */
void	rra(t_stack **a)
{
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	last = *a;
	while (last->next->next)
		last = last->next;
	ps_lstadd(a, last->next, FRONT);
	last->next = NULL;
	ft_putstr_fd("rra\n", 1);
}
