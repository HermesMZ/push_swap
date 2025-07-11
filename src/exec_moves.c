/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:01:05 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/08 12:11:47 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	execute_rr(t_swap *swap, t_cost *cost)
{
	while (cost->rr != 0)
	{
		if (cost->rr > 0)
		{
			ft_rotate_rr(swap);
			cost->rr--;
		}
		if (cost->rr < 0)
		{
			ft_reverse_rotate_rr(swap);
			cost->rr++;
		}
	}
}

static void	execute_ra(t_swap *swap, t_cost *cost)
{
	while (cost->ra != 0)
	{
		if (cost->ra > 0)
		{
			ft_rotate(swap, swap->stack_a->first);
			cost->ra--;
		}
		if (cost->ra < 0)
		{
			ft_reverse_rotate(swap, swap->stack_a->first);
			cost->ra++;
		}
	}
}

static void	execute_rb(t_swap *swap, t_cost *cost)
{
	while (cost->rb != 0)
	{
		if (cost->rb > 0)
		{
			ft_rotate(swap, swap->stack_b->first);
			cost->rb--;
		}
		if (cost->rb < 0)
		{
			ft_reverse_rotate(swap, swap->stack_b->first);
			cost->rb++;
		}
	}
}

void	execute_optimal_moves(t_swap *swap, t_cost *cost)
{
	execute_rr(swap, cost);
	execute_ra(swap, cost);
	execute_rb(swap, cost);
	ft_push(swap, cost->elem);
}

void	push_back_to_a_optimized(t_swap *swap)
{
	t_cost	*cheapest_cost;

	while (swap->stack_b->len > 0)
	{
		cheapest_cost = find_cheapest_element(swap, swap->stack_b, 0, 0);
		if (!cheapest_cost)
			return ;
		execute_optimal_moves(swap, cheapest_cost);
		free_cost_if_not_null(&cheapest_cost);
	}
	free_cost_if_not_null(&cheapest_cost);
}
