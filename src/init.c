/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:46:38 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:23:04 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_stack_init(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->first = NULL;
	new_stack->last = NULL;
	new_stack->len = 0;
	new_stack->min = 0;
	new_stack->max = 0;
	return (new_stack);
}

static t_swap_int	*new_swap_int(int value)
{
	t_swap_int	*new_elem;

	new_elem = malloc(sizeof(t_swap_int));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->index = 0;
	new_elem->stack = NULL;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->locked = 0;
	return (new_elem);
}

static void	ft_stack_add_back(t_stack *stack, int value)
{
	t_swap_int	*new_elem;

	if (!stack)
		return ;
	new_elem = new_swap_int(value);
	if (!new_elem)
		return ;
	if (stack->len == 0)
	{
		stack->first = new_elem;
		stack->last = new_elem;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	else
	{
		stack->last->next = new_elem;
		new_elem->prev = stack->last;
		stack->last = new_elem;
		new_elem->next = stack->first;
		stack->first->prev = new_elem;
	}
	new_elem->stack = stack;
	stack->len++;
}

static void	init_stack_a(t_swap *swap, char *argv[], size_t len)
{
	size_t	i;

	i = 1;
	swap->stack_a = ft_stack_init();
	if (!swap->stack_a)
		return ;
	while (i <= len)
		ft_stack_add_back(swap->stack_a, ft_atoi(argv[i++]));
	swap->stack_a->first->prev = swap->stack_a->last;
	swap->stack_a->last->next = swap->stack_a->first;
}

t_swap	*swap_init(t_swap *swap, char *argv[], size_t len)
{
	t_list	*move;

	move = ft_lstnew(ft_strdup("start"));
	swap = malloc(sizeof(t_swap));
	if (!swap)
		return (NULL);
	init_stack_a(swap, argv, len);
	swap->stack_b = ft_stack_init();
	if (!swap->stack_a || !swap->stack_b)
		return (NULL);
	swap->stack_b->max = 0;
	swap->stack_b->min = 0;
	fill_index(swap->stack_a);
	set_min_max(swap->stack_a);
	swap->min = swap->stack_a->min;
	swap->max = swap->stack_a->max;
	find_index(swap->stack_a, swap->stack_a->min)->locked = 1;
	find_index(swap->stack_a, swap->stack_a->max)->locked = 1;
	swap->move = move;
	return (swap);
}
