/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:11:25 by zoum              #+#    #+#             */
/*   Updated: 2025/07/10 11:55:06 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*read_move(int fd)
{
	char	buffer[1];
	char	*line;
	int		bytes_read;
	size_t	len;

	line = NULL;
	len = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
			return (free(line), (char *) NULL);
		if (bytes_read == 0 || buffer[0] == '\n')
			break ;
		line = (char *)realloc(line, len + 2);
		if (!line)
			return (NULL);
		line[len] = buffer[0];
		len++;
	}
	if (len == 0 && bytes_read == 0)
		return (free(line), (char *) NULL);
	if (line)
		line[len] = '\0';
	return (line);
}

static int	check_end(t_swap *swap)
{
	if (swap->stack_b->len == 0
		&& is_sorted(swap->stack_a->len, swap->stack_a->first))
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (0);
	}
}

int	main(int argc, char *argv[])
{
	size_t		len;
	t_swap		*swap;
	char		*move;

	swap = NULL;
	if (argc < 2)
		return (0);
	len = (size_t)argc - 1;
	if (!check_input(argv))
		return (error());
	swap = swap_init(swap, argv, len);
	if (!swap)
		return (error());
	while (1)
	{
		move = read_move(0);
		if (move == NULL)
		{
			check_end(swap);
			break ;
		}
		check_and_do_move(swap, move);
	}
	return (free_all(swap), 0);
}
