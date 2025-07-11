/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/10 11:26:33 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_moves(t_list *move)
{
	t_list	*current;
	int		total_commands;

	total_commands = 0;
	current = move;
	current = current->next;
	while (current)
	{
		ft_printf("%s", current->content);
		total_commands++;
		current = current->next;
	}
}

static int	calculate_chunk_count(size_t len)
{
	if (len <= 100)
		return (1);
	else if (len <= 500)
		return (5);
	else
		return (len / 25);
}

static void	sort(t_swap *swap)
{
	t_swap_int	*pivot;

	pivot = find_median(swap->stack_a->first, swap->stack_a->len);
	while (swap->stack_a->len > 3)
	{
		if (swap->stack_a->first->index == swap->max)
			ft_rotate(swap, swap->stack_a->first);
		ft_push(swap, swap->stack_a->first);
		if (swap->stack_b->first->index > pivot->index)
			ft_rotate(swap, swap->stack_b->first);
	}
	hard_sort(swap, swap->stack_a->first, swap->stack_a->len);
	push_back_to_a_optimized(swap);
}

int	main(int argc, char *argv[])
{
	size_t		len;
	t_swap		*swap;
	int			chunks;

	swap = NULL;
	if (argc < 2)
		return (0);
	len = (size_t)argc - 1;
	if (!check_input(argv))
		return (error());
	swap = swap_init(swap, argv, len);
	if (!swap)
		return (error());
	if (is_circularly_sorted(swap->stack_a) != 1)
	{
		chunks = calculate_chunk_count(len);
		if (chunks > 1)
			push_chunks(swap, chunks);
		sort(swap);
	}
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
	print_moves(swap->move);
	free_all(swap);
	return (0);
}
