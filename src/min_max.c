/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:15:42 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:29:22 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_min_max_on_push(t_swap_int *elem)
{
	if (!elem)
		return ;
	if (elem->index < elem->stack->min || elem->stack->len == 1)
		elem->stack->min = elem->index;
	if (elem->index > elem->stack->max || elem->stack->len == 1)
		elem->stack->max = elem->index;
}

static void	update_min_max_on_pop(t_swap *swap, t_swap_int *elem)
{
	t_stack	*prev;

	if (!elem)
		return ;
	if (elem->stack == swap->stack_a)
		prev = swap->stack_b;
	else
		prev = swap->stack_a;
	if (elem->index == prev->min || elem->index == prev->max)
		set_min_max(prev);
}

void	update_min_max(t_swap *swap, t_swap_int *elem)
{
	update_min_max_on_pop(swap, elem);
	update_min_max_on_push(elem);
}

void	set_min_max(t_stack *stack)
{
	int			min;
	int			max;
	size_t		i;
	t_swap_int	*current;

	if (stack->len == 0)
		return ;
	i = 0;
	min = stack->first->index;
	max = stack->first->index;
	current = stack->first;
	while (i <= stack->len)
	{
		if (current->index < min)
			min = current->index;
		if (current->index > max)
			max = current->index;
		current = current->next;
		i++;
	}
	stack->max = max;
	stack->min = min;
}
