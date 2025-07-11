/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:04:21 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:28:37 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_a_b(t_swap *swap, t_swap_int *elem)
{
	if (!swap || !elem || elem->stack->len < 2)
		return ;
	elem->stack->first = elem->stack->first->prev;
	elem->stack->last = elem->stack->last->prev;
}

void	ft_reverse_rotate(t_swap *swap, t_swap_int *elem)
{
	ft_reverse_rotate_a_b(swap, elem);
	if (elem->stack == swap->stack_a)
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("rra\n")));
	else
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("rrb\n")));
}

void	ft_reverse_rotate_rr(t_swap *swap)
{
	if (!swap)
		return ;
	ft_reverse_rotate_a_b(swap, swap->stack_a->first);
	ft_reverse_rotate_a_b(swap, swap->stack_b->first);
	ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("rrr\n")));
}
