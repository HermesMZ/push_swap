/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:52:01 by zoum              #+#    #+#             */
/*   Updated: 2025/07/09 13:52:58 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_and_do_a_move(t_swap *swap, char *move)
{
	if (ft_strncmp(move, "sa", 3) == 0)
	{
		ft_swap(swap, swap->stack_a->first);
		return (1);
	}
	else if (ft_strncmp(move, "ra", 3) == 0)
	{
		ft_rotate(swap, swap->stack_a->first);
		return (1);
	}
	else if (ft_strncmp(move, "rra", 3) == 0)
	{
		ft_reverse_rotate(swap, swap->stack_a->first);
		return (1);
	}
	return (0);
}

static int	check_and_do_b_move(t_swap *swap, char *move)
{
	if (ft_strncmp(move, "sb", 3) == 0)
	{
		ft_swap(swap, swap->stack_b->first);
		return (1);
	}
	else if (ft_strncmp(move, "rb", 3) == 0)
	{
		ft_rotate(swap, swap->stack_b->first);
		return (1);
	}
	else if (ft_strncmp(move, "rrb", 3) == 0)
	{
		ft_reverse_rotate(swap, swap->stack_b->first);
		return (1);
	}
	return (0);
}

static int	check_and_do_combined_or_push_move(t_swap *swap, char *move)
{
	if (ft_strncmp(move, "ss", 3) == 0)
	{
		ft_swap_ss(swap);
		return (1);
	}
	else if (ft_strncmp(move, "rr", 3) == 0)
	{
		ft_rotate_rr(swap);
		return (1);
	}
	else if (ft_strncmp(move, "rrr", 3) == 0)
	{
		ft_reverse_rotate_rr(swap);
		return (1);
	}
	else if (ft_strncmp(move, "pa", 3) == 0)
		return (ft_push(swap, swap->stack_b->first), 1);
	else if (ft_strncmp(move, "pb", 3) == 0)
		return (ft_push(swap, swap->stack_a->first), 1);
	return (0);
}

int	check_and_do_move(t_swap *swap, char *move)
{
	if (check_and_do_a_move(swap, move))
	{
		free(move);
		return (0);
	}
	else if (check_and_do_b_move(swap, move))
	{
		free(move);
		return (0);
	}
	else if (check_and_do_combined_or_push_move(swap, move))
	{
		free(move);
		return (0);
	}
	else
	{
		free(move);
		error();
		free_all(swap);
		exit(1);
	}
}
