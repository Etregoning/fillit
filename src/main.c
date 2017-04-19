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
#include <stdio.h>

int		solver(int *tetindex)
{
	char	**tetarray;
	char	**board;
	int		size;

	size = find_board_size(tetindex);
	if (!(board = build_board(size, size)))
		return (1);
	if (!(tetarray = create_tet(tetindex)))
		return (1);
	while (recursor(board, tetarray, 0, 0))
	{
		++size;
		ft_tbldel(board);
		if (!(board = build_board(size, size)))
			return (1);
	}
	cleanup_board(board);
	ft_puttbl(board);
	return (0);
}

int		*validation(char *src)
{
	int   len;
	int		lines;
	int		blck_cnt;
	char	**src_tbl;
	int		*tetri;

	len = 0;
	lines = 0;
	blck_cnt = 0;
	validate1(src, &len, &lines);
	if (len < 20 || lines > 129)
		return (0);
	if (validate2(src, &blck_cnt) || blck_cnt > 26)
		return (0);
	if (!(src_tbl = ft_tblnew(blck_cnt, 20)))
		return (0);
	assign_tbl(src_tbl, src);
	if (tbl_trim(src_tbl) || (!(tetri = validate3(src_tbl))))
	{
		ft_tbldel(src_tbl);
		return (0);
	}
	ft_tbldel(src_tbl);
	return (tetri);
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
	if (!(piece = validation(src)))
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
		ft_error();
	exit(0);
	return (0);
}
