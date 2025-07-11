/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:05:53 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:39:57 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cost	*cost_raw_rotations(t_swap_int *elem_a, t_swap_int *elem_b)
{
	t_cost	*cost;

	cost = init_empty_cost();
	if (!cost)
		return (NULL);
	if (elem_a)
		cost->ra = r_or_rr(elem_a);
	if (elem_b)
		cost->rb = r_or_rr(elem_b);
	cost->elem = elem_a;
	return (cost);
}

static t_cost	*calculate_cost_for_a_to_b(t_swap *swap, t_swap_int *elem_a)
{
	t_cost		*cost;
	t_swap_int	*target_b;

	target_b = get_target(swap, elem_a);
	cost = cost_raw_rotations(elem_a, target_b);
	if (!cost)
		return (NULL);
	if (cost->ra == 0)
		cost->rb = 0;
	if (cost->ra > 0 && cost->rb > 0 && cost->ra > cost->rb)
	{
		cost->rr = ft_min(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	else if (cost->ra < 0 && cost->rb < 0 && cost->ra < cost->rb)
	{
		cost->rr = ft_max(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	cost->rb = 0;
	cost->total = ft_abs(cost->ra) + ft_abs(cost->rb) + ft_abs(cost->rr) + 1;
	cost->elem = elem_a;
	return (cost);
}

static t_cost	*calculate_cost_for_b_to_a(t_swap *swap, t_swap_int *elem_b)
{
	t_cost		*cost;
	t_swap_int	*target_a;

	target_a = get_target(swap, elem_b);
	cost = cost_raw_rotations(target_a, elem_b);
	if (!cost)
		return (NULL);
	cost->rr = 0;
	if (cost->ra > 0 && cost->rb > 0)
	{
		cost->rr = ft_min(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	else if (cost->ra < 0 && cost->rb < 0)
	{
		cost->rr = ft_max(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	cost->total = ft_abs(cost->ra) + ft_abs(cost->rb) + ft_abs(cost->rr) + 1;
	cost->elem = elem_b;
	return (cost);
}

static t_cost	*calculate_cost(t_swap *swap, t_swap_int *current,
	t_cost *cheapest_cost)
{
	t_cost		*current_cost;

	if (current->stack == swap->stack_a)
		current_cost = calculate_cost_for_a_to_b(swap, current);
	else
		current_cost = calculate_cost_for_b_to_a(swap, current);
	if (!current_cost)
		return (free_cost_if_not_null(&cheapest_cost), (t_cost *) NULL);
	if (!cheapest_cost || current_cost->total < cheapest_cost->total)
	{
		free_cost_if_not_null(&cheapest_cost);
		cheapest_cost = current_cost;
	}
	else
		free_cost_if_not_null(&current_cost);
	return (cheapest_cost);
}

t_cost	*find_cheapest_element(t_swap *swap, t_stack *source_stack,
	int chunk_min, int chunk_max)
{
	t_swap_int	*current;
	t_cost		*cheapest_cost;
	size_t		i;

	cheapest_cost = NULL;
	current = source_stack->first;
	i = 0;
	while (i < source_stack->len)
	{
		if ((source_stack == swap->stack_a
				&& (current->index >= chunk_min
					&& current->index <= chunk_max))
			|| (source_stack == swap->stack_b))
			cheapest_cost = calculate_cost(swap, current, cheapest_cost);
		current = current->next;
		i++;
	}
	return (cheapest_cost);
}
