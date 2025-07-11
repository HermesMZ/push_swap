/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:15:54 by zoum              #+#    #+#             */
/*   Updated: 2025/06/28 02:11:23 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_sort_3(t_swap *swap, t_swap_int *elem, int ascending)
{
	if ((ascending && elem->index > elem->next->index)
		|| (!ascending && elem->index < elem->next->index))
	{
		ft_swap(swap, elem);
		elem = elem->stack->first;
	}
	if ((ascending && elem->next->index > elem->next->next->index)
		|| (!ascending && elem->next->index < elem->next->next->index))
	{
		ft_rotate(swap, elem);
		ft_swap(swap, elem);
		ft_reverse_rotate(swap, elem);
		elem = elem->stack->first;
	}
	if ((ascending && elem->index > elem->next->index)
		|| (!ascending && elem->index < elem->next->index))
		ft_swap(swap, elem);
}

void	hard_sort(t_swap *swap, t_swap_int *elem, int count)
{
	t_swap_int	*to;

	rotate_to(swap, elem);
	if (!elem || !count)
		return ;
	if (elem->stack == swap->stack_b)
		to = swap->stack_b->first;
	else
		to = swap->stack_a->first;
	if (count == 2)
	{
		if ((to->index > to->next->index && to->stack == swap->stack_a)
			|| (to->index < to->next->index && to->stack == swap->stack_b))
			ft_swap(swap, to);
	}
	if (count == 3)
		hard_sort_3(swap, elem, elem->stack == swap->stack_a);
}
