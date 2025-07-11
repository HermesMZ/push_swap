/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:11:52 by zoum              #+#    #+#             */
/*   Updated: 2025/07/11 10:46:39 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Use ./bash to use the checker so that args are splitted.
// I did not change zsh settings nor implement a split logic.

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include "libft.h"
# include "push_swap.h"

int	check_and_do_move(t_swap *swap, char *move);

#endif /*CHECKER_H*/