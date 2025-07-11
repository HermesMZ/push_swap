/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 01:22:10 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:52:04 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_swap_int
{
	struct s_swap_int	*prev;
	struct s_swap_int	*next;
	int					value;
	int					index;
	int					locked;
	struct s_stack		*stack;
}	t_swap_int;

typedef struct s_cost
{
	int			ra;
	int			rb;
	int			rr;
	int			total;
	t_swap_int	*elem;
}	t_cost;

typedef struct s_stack
{
	t_swap_int	*first;
	t_swap_int	*last;
	int			min;
	int			max;
	size_t		len;
}	t_stack;

typedef struct s_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			min;
	int			max;
	t_swap_int	*best_start;
	t_list		*move;
}	t_swap;

// init
t_swap		*swap_init(t_swap *swap, char *argv[], size_t len);

// check_input
int			check_input(char *argv[]);
int			error(void);

// index
void		fill_index(t_stack *stack);
t_swap_int	*find_index(t_stack *stack, int i);
t_swap_int	*find_median(t_swap_int *first, int count);


// sort_utils
int			is_sorted(size_t length, t_swap_int *elem);
int			is_circularly_sorted(t_stack *stack);
void		rotate_to(t_swap *swap, t_swap_int *elem);
int			r_or_rr(t_swap_int *target);

// chunk
void		push_chunks(t_swap *swap, int nb_chunks);
int			has_chunk(t_stack *stack, int chunk_min, int chunk_max);
t_swap_int	*find_next_chunk_elem(t_swap_int *current, int chunk_min,
				int chunk_max);

// hard_sort
void		hard_sort(t_swap *swap, t_swap_int *elem, int count);

// min_max
void		set_min_max(t_stack *stack);
void		update_min_max(t_swap *swap, t_swap_int *elem);

// cost
t_cost		*find_cheapest_element(t_swap *swap, t_stack *source_stack,
				int chunk_min, int chunk_max);

// cost_target
t_swap_int	*get_target(t_swap *swap, t_swap_int *source);

// cost_utils
t_cost		*init_empty_cost(void);
void		free_cost_if_not_null(t_cost **cost);

// exec_moves
void		execute_optimal_moves(t_swap *swap, t_cost *cost);
void		push_back_to_a_optimized(t_swap *swap);

// operations
void		ft_push(t_swap *swap, t_swap_int *elem);
void		ft_swap(t_swap *swap, t_swap_int *elem);
void		ft_swap_ss(t_swap *swap);
void		ft_rotate(t_swap *swap, t_swap_int *elem);
void		ft_rotate_rr(t_swap *swap);
void		ft_reverse_rotate(t_swap *swap, t_swap_int *elem);
void		ft_reverse_rotate_rr(t_swap *swap);

// simple maths
int			ft_abs(int x);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

// utils
void		debug_print_stacks(t_swap *swap);
void		free_all(t_swap *swap);

#endif /*PUSH_SWAP_H*/
