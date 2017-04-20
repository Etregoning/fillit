/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:48:13 by etregoni          #+#    #+#             */
/*   Updated: 2017/03/22 17:48:20 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solver(int *index)
{
	char	**tet;
	char	**board;
	int		size;

	size = board_size(index);
	if (!(board = create_board(size, size)))
		return (1);
	if (!(tet = create_tet(index)))
		return (1);
	while (recursor(board, tet, 0, 0))
	{
		++size;
		tbldel(board);
		if (!(board = create_board(size, size)))
			return (1);
	}
	cleanup_board(board);
	puttbl(board);
	return (0);
}

int		*validation(char *src)
{
	int		len;
	int		lines;
	int		blocks;
	char	**table;
	int		*piece;

	len = 0;
	lines = 0;
	blocks = 0;
	valid_char(src, &len, &lines);
	if (len < 20 || lines > 129)
		return (0);
	if (validate_count(src, &blocks) || blocks > 26)
		return (0);
	if (!(table = tblnew(blocks, 20)))
		return (0);
	assign_tbl(table, src);
	if (tbl_trim(table) || (!(piece = validate_pattern(table))))
	{
		tbldel(table);
		return (0);
	}
	tbldel(table);
	return (piece);
}

int		close_delete(int flag, int fd, char *board)
{
	if (flag == 1 || flag == 3)
		close(fd);
	if (flag == 2 || flag == 3)
		ft_strdel(&board);
	return (1);
}

int		open_file(char *file)
{
	int		fd;
	char	*src;
	int		*board;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (1);
	if (!(src = ft_strnew(545)))
		return (close_delete(1, fd, src));
	if (read(fd, src, 545) == -1 || read(fd, src, 1) != 0)
		return (close_delete(3, fd, src));
	close(fd);
	if (!(board = validation(src)))
		return (close_delete(2, fd, src));
	ft_strdel(&src);
	if (solver(board))
	{
		free(board);
		return (1);
	}
	free(board);
	return (0);
}

int		main(int ac, char *av[])
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(1);
		return (1);
	}
	if (open_file(av[1]))
	{
		ft_putstr("error\n");
		exit(1);
		return (1);
	}
	exit(0);
	return (0);
}
