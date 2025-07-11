/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:39:06 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 10:49:20 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_two(t_stack *stack)
{
	t_swap_int	*first;
	t_swap_int	*second;

	first = stack->first;
	second = first->next;
	first->next = second;
	first->prev = second;
	second->next = first;
	second->prev = first;
	stack->first = second;
	stack->last = first;
}

void	ft_swap(t_swap *swap, t_swap_int *elem)
{
	t_swap_int	*first;
	t_swap_int	*second;
	t_swap_int	*third;

	if (!swap || !elem || elem->stack->len < 2)
		return ;
	if (elem->stack->len == 2)
		ft_swap_two(elem->stack);
	else
	{
		first = elem->stack->first;
		second = first->next;
		third = second->next;
		second->prev = first->prev;
		second->next = first;
		first->prev->next = second;
		first->prev = second;
		first->next = third;
		third->prev = first;
		elem->stack->first = second;
	}
	if (elem->stack == swap->stack_a)
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("sa\n")));
	else
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("sb\n")));
}

void	ft_swap_ss(t_swap *swap)
{
	if (!swap)
		return ;
	ft_swap(swap, swap->stack_a->first);
	ft_swap(swap, swap->stack_b->first);
}
