/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:55:44 by zoum              #+#    #+#             */
/*   Updated: 2025/07/16 17:57:50 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_cost(t_cost **cost)
{
	if (*cost)
	{
		free(*cost);
		*cost = NULL;
	}
}

t_cost	*init_empty_cost(void)
{
	t_cost	*cost;

	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->ra = 0;
	cost->rb = 0;
	cost->rr = 0;
	cost->total = -1;
	cost->elem = NULL;
	return (cost);
}
