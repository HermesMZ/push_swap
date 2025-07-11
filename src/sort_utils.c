/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:49:09 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 12:25:02 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_circularly_sorted(t_stack *stack)
{
	t_swap_int	*current;
	size_t		i;
	int			asc_breaks;
	int			desc_breaks;

	if (!stack || stack->len <= 1)
		return (1);
	current = stack->first;
	asc_breaks = 0;
	desc_breaks = 0;
	i = 0;
	while (i < stack->len)
	{
		if (current->index > current->next->index)
			asc_breaks++;
		if (current->index < current->next->index)
			desc_breaks++;
		current = current->next;
		i++;
	}
	if (asc_breaks == 0 || asc_breaks == 1)
		return (1);
	else if (desc_breaks == 0 || desc_breaks == 1)
		return (-1);
	return (0);
}

int	is_sorted(size_t len, t_swap_int *elem)
{
	t_swap_int	*current;
	int			order;
	size_t		i;

	if (!elem || len <= 1)
		return (1);
	current = elem;
	order = current->index - current->next->index;
	i = 0;
	while (i < len - 1 && order)
	{
		if (current->index > current->next->index && order < 0)
			return (0);
		if (current->index < current->next->index && order > 0)
			return (0);
		current = current->next;
		i++;
	}
	return (-order);
}

int	r_or_rr(t_swap_int *target)
{
	int			r_count;
	int			rr_count;
	t_swap_int	*current;

	if (!target || !target->stack || target->stack->len == 0)
		return (0);
	r_count = 0;
	current = target->stack->first;
	while (current && current != target)
	{
		current = current->next;
		r_count++;
		if (r_count > (int)target->stack->len)
			return (-1);
	}
	if (r_count == 0)
		rr_count = 0;
	else
		rr_count = target->stack->len - r_count;
	if (r_count <= rr_count)
		return (r_count);
	else
		return (-rr_count);
}

void	rotate_to(t_swap *swap, t_swap_int *elem)
{
	int	start;

	if (!swap || !elem || elem == elem->stack->first)
		return ;
	start = r_or_rr(elem);
	{
		while (elem->stack->first != elem)
		{
			if (start < 0)
				ft_reverse_rotate(swap, elem);
			else if (start > 0)
				ft_rotate(swap, elem);
		}
	}
}
