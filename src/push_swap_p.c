/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:09:05 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 23:25:56 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap_int	*ft_remove_from_stack(t_stack *stack)
{
	t_swap_int	*elem_to_remove;

	if (stack->len == 0)
		return (NULL);
	elem_to_remove = stack->first;
	if (stack->len == 1)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->first = elem_to_remove->next;
		stack->first->prev = stack->last;
		stack->last->next = stack->first;
	}
	stack->len--;
	return (elem_to_remove);
}

static void	ft_push_from_to(t_stack *from, t_stack *to)
{
	t_swap_int	*elem_to_push;

	elem_to_push = ft_remove_from_stack(from);
	if (!elem_to_push)
		return ;
	if (to->len == 0)
	{
		elem_to_push->next = elem_to_push;
		elem_to_push->prev = elem_to_push;
		to->last = elem_to_push;
	}
	else
	{
		elem_to_push->next = to->first;
		elem_to_push->prev = to->last;
		to->first->prev = elem_to_push;
		to->last->next = elem_to_push;
	}
	to->first = elem_to_push;
	elem_to_push->stack = to;
	to->len++;
}

void	ft_push(t_swap *swap, t_swap_int *elem)
{
	t_stack	*from;
	t_stack	*to;

	from = elem->stack;
	if (from == swap->stack_a)
		to = swap->stack_b;
	else
		to = swap->stack_a;
	ft_push_from_to(from, to);
	set_min_max(swap->stack_a);
	set_min_max(swap->stack_b);
	if (from == swap->stack_a)
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("pb\n")));
	else
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("pa\n")));
}
