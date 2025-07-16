/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:15:54 by zoum              #+#    #+#             */
/*   Updated: 2025/07/16 16:52:49 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_sort_3(t_swap *swap)
{
	if (is_circularly_sorted(swap->stack_a) != 1)
		ft_swap(swap, swap->stack_a->first);
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
}

void	hard_sort(t_swap *swap)
{
	if (swap->stack_a->len == 2)
	{
		if (swap->stack_a->first->index > swap->stack_a->last->index)
			ft_swap(swap, swap->stack_a->first);
	}
	if (swap->stack_a->len == 3)
		hard_sort_3(swap);
}
