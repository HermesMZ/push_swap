/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:33:51 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/10 11:38:04 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap_int	*get_target_in_a(t_stack *stack_a, t_swap_int *elem_b)
{
	t_swap_int	*current_a;

	if (!stack_a || stack_a->len == 0)
		return (NULL);
	current_a = stack_a->first;
	if (elem_b->index < stack_a->min || elem_b->index > stack_a->max)
		return (find_index(stack_a, stack_a->min));
	while (current_a && current_a->next)
	{
		if (current_a->index < elem_b->index
			&& elem_b->index < current_a->next->index)
			return (current_a->next);
		if (current_a->index == stack_a->max && elem_b->index < stack_a->min)
			return (stack_a->first);
		current_a = current_a->next;
	}
	return (NULL);
}

static t_swap_int	*get_target_in_b(t_stack *stack_b, t_swap_int *elem_a)
{
	t_swap_int	*current_b;
	t_swap_int	*target_b;
	size_t		i;

	target_b = NULL;
	if (stack_b->len == 0)
		return (NULL);
	current_b = stack_b->first;
	i = 0;
	while (i < stack_b->len)
	{
		if (current_b->index < elem_a->index
			&& current_b->prev->index > elem_a->index)
		{
			target_b = current_b;
			break ;
		}
		current_b = current_b->next;
		i++;
	}
	return (target_b);
}

t_swap_int	*get_target(t_swap *swap, t_swap_int *source)
{
	if (source->stack == swap->stack_a)
		return (get_target_in_b(swap->stack_b, source));
	else
		return (get_target_in_a(swap->stack_a, source));
}
