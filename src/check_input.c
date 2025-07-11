/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:32:51 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/10 11:26:36 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1] != '\0')
		i++;
	while (argv[i] && ft_isdigit(argv[i]))
		i++;
	if (argv[i] != '\0' && !ft_isdigit(argv[i]))
		return (0);
	return (1);
}

static int	has_double(char *argv[])
{
	int		i;
	int		j;
	long	val_i;
	long	val_j;

	i = 1;
	while (argv[i])
	{
		val_i = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			val_j = ft_atoi(argv[j]);
			if (val_i == val_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	zero(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '-' || argv[i] == '+'))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char *argv[])
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		nb_zeros += zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (has_double(argv))
		return (0);
	return (1);
}

int	error(void)
{
	write (2, "Error\n", 6);
	return (1);
}
