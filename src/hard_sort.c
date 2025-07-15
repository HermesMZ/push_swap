/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:15:54 by zoum              #+#    #+#             */
/*   Updated: 2025/07/15 19:39:31 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_sort_3(t_swap *swap)
{
	t_swap_int	*elem;

	elem = swap->stack_a->first;
	if (is_circularly_sorted(swap->stack_a) != 1)
		ft_swap(swap, swap->stack_a->first);
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
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
		if (to->index > to->next->index && to->stack == swap->stack_a)
			ft_swap(swap, to);
	}
	if (count == 3)
		hard_sort_3(swap);
}
