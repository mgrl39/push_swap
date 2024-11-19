/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meghribe <meghribe@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:08:08 by meghribe          #+#    #+#             */
/*   Updated: 2024/11/14 14:05:13 by meghribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
	int				index;
}	t_stack;

typedef enum t_position
{
	FRONT,
	BACK
}	t_pos;

typedef enum t_free_option
{
	FREE_ARGS,
	FREE_STACK
}	t_free_opt;

typedef enum t_push_direction
{
	TO_A,
	TO_B
}	t_push_dir;

typedef enum t_char_type
{
	DIGIT,
	SPACE,
	SYMBOL
}	t_char_type;

void	choose_sort_algorithm(t_stack **a, t_stack **b);
int		get_max_bits(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b);
int		ft_strcmp(char *s1, char *s2);
void	check_if_repeated(char **argv);
char	**ft_split(char const *s, char c);
int		ps_atoi(const char *str, int *result);
int		push_to_stack(t_stack **stack, int value);
int		*stack_to_array(t_stack *stack, int size);
void	assign_index(t_stack *stack, int *sorted_array, int size);
void	index_stack(t_stack **a);
int		ps_lstsize(t_stack *lst);
t_stack	*ps_lstnew(int number);
t_stack	*ps_lstlast(t_stack *lst);
void	check_duplicates(t_stack **stack_a);
void	check_if_sorted(t_stack **stack_a);
int		handle_args(int argc, char *argv[], t_stack **stack_a);
void	sa(t_stack **lst);
void	ps_push(t_stack **src, t_stack **dest, t_push_dir direction);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	ft_putstr_fd(char *s, int fd);
void	sort_three(t_stack **a);
int		find_min_value(t_stack *stack);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
int		is_only_spaces(char *str);
void	ft_free_stack_or_args(t_stack **stack, char **args, t_free_opt option);
void	ps_lstadd(t_stack **lst, t_stack *new, t_pos pos);
int		ft_ischar(int c, t_char_type type);
#endif
