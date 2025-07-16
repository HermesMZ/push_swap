/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:08:42 by zoum              #+#    #+#             */
/*   Updated: 2025/07/16 17:58:43 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_elems(t_swap *swap, t_swap_int **a, t_swap_int **b, size_t i)
{
	if ((*a))
	{
		if ((*a)->locked)
			ft_printf("X%8dX ", (*a)->value);
		else
			ft_printf("%10d ", (*a)->value);
		if ((*a)->next && i + 1 < swap->stack_a->len)
			(*a) = (*a)->next;
		else
			(*a) = NULL;
	}
	else
		ft_printf("%11c", ' ');
	if ((*b))
	{
		ft_printf("%10d", (*b)->value);
		if ((*b)->next && i + 1 < swap->stack_b->len)
			(*b) = (*b)->next;
		else
			(*b) = NULL;
	}
	ft_printf("\n");
}

void	debug_print_stacks(t_swap *swap)
{
	t_swap_int	*a;
	t_swap_int	*b;
	t_stack		*stack_a;
	t_stack		*stack_b;
	size_t		i;

	stack_a = swap->stack_a;
	stack_b = swap->stack_b;
	a = stack_a->first;
	b = stack_b->first;
	ft_printf("\n%10c %10c\n%10d %10d\n\n", 'a', 'b',
		stack_a->len, stack_b->len);
	ft_printf("min-a %4d min-b %4d\n", swap->stack_a->min,
		swap->stack_b->min);
	ft_printf("max-a %4d max-b %4d\n\n", swap->stack_a->max,
		swap->stack_b->max);
	i = 0;
	while (i < stack_a->len || i < stack_b->len)
	{
		print_elems(swap, &a, &b, i);
		i++;
	}
	ft_printf("commands done : %d\n", ft_lstsize(swap->move) - 1);
}

static void	ft_del_swapint(t_swap_int *p_elem)
{
	if (!p_elem)
		return ;
	free(p_elem);
	p_elem = NULL;
}

static void	ft_stack_clear(t_stack **p_lst, void (*del)(void*))
{
	t_swap_int	*current;
	t_swap_int	*next_elem;

	if (!p_lst || !*p_lst || !del)
		return ;
	if ((*p_lst)->len == 0)
	{
		free(*p_lst);
		*p_lst = NULL;
		return ;
	}
	(*p_lst)->last->next = NULL;
	current = (*p_lst)->first;
	while (current)
	{
		next_elem = current->next;
		ft_del_swapint(current);
		current = next_elem;
	}
	free(*p_lst);
	*p_lst = NULL;
}

void	free_all(t_swap *swap)
{
	ft_lstclear(&swap->move, free);
	ft_stack_clear(&swap->stack_a, free);
	ft_stack_clear(&swap->stack_b, free);
	free(swap);
}
