/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 22:56:11 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:30:35 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_int	*find_index(t_stack *stack, int i)
{
	t_swap_int	*current;

	current = stack->first;
	while (current->index != i)
		current = current->next;
	return (current);
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	quick_sort(int tab[], int first, int last)
{
	int	pivot;
	int	i;
	int	j;

	if (first < last)
	{
		pivot = first;
		i = first;
		j = last;
		while (i < j)
		{
			while (tab[i] <= tab[pivot] && i < last)
				i++;
			while (tab[j] > tab[pivot])
				j--;
			if (i < j)
				swap(&tab[i], &tab[j]);
		}
		swap(&tab[pivot], &tab[j]);
		quick_sort(tab, first, j - 1);
		quick_sort(tab, j + 1, last);
	}
}

void	fill_index(t_stack *stack)
{
	int			*array;
	size_t		i;
	t_swap_int	*current;

	i = 0;
	array = malloc(sizeof(int) * (stack->len + 1));
	if (!array)
		return ;
	current = stack->first;
	while (i < stack->len)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}
	array[i] = '\0';
	quick_sort(array, 0, i - 1);
	while (--i > 0)
	{
		while (current->value != array[i])
			current = current->next;
		current->index = i;
	}
	free(array);
}

t_swap_int	*find_median(t_swap_int *first, int count)
{
	int			*array;
	int			i;
	t_stack		*stack;
	t_swap_int	*cursor;
	t_swap_int	*median;

	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	cursor = first;
	stack = first->stack;
	i = 0;
	while (i < count && cursor)
	{
		if (!cursor->locked)
		{
			array[i] = cursor->index;
			i++;
		}
		cursor = cursor->next;
	}
	quick_sort(array, 0, i - 1);
	median = find_index(stack, array[(i - 1) / 2]);
	free(array);
	return (median);
}
