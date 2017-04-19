/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:21:37 by etregoni          #+#    #+#             */
/*   Updated: 2017/04/18 01:18:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**finish_board(char **board, int size, int str_size, int i)
{
	int		j;

	while (i < size + 3)
	{
		j = 0;
		while (j < (str_size + 3))
		{
			board[i][j] = 'x';
			j++;
		}
		i++;
	}
	return (board);
}

char	**build_board(int size, int str_size)
{
	char	**board;
	int		i;
	int		j;

	i = 0;
	if (!(board = ft_tblnew(size + 3, str_size + 3)))
		return (0);
	while (i < size)
	{
		j = 0;
		while (j < (str_size))
		{
			board[i][j] = '.';
			j++;
		}
		board[i][j + 1] = 'x';
		board[i][j + 2] = 'x';
		board[i][j + 3] = 'x';
		i++;
	}
	return (finish_board(board, size, str_size, i));
}

char	**convert_array(char **tetarray)
{
	int		i;
	int		j;

	i = 0;
	while (tetarray[i])
	{
		j = 0;
		while (tetarray[i][j])
		{
			if (tetarray[i][j] == '#')
				tetarray[i][j] = ('A' + i);
			j++;
		}
		i++;
	}
	return (tetarray);
}

int		find_board_size(int *tetindex)
{
	int		i;
	int		j;

	i = 0;
	while (tetindex[i] != 42)
		i++;
	i = i * 4;
	j = 2;
	while (i > (j * j))
		j++;
	return (j);
}

void	cleanup_board(char **board)
{
	int row;
	int col;

	row = 0;
	while (board[row])
	{
		col = 0;
		if (board[row][col] == 'x')
			board[row] = 0;
		else
		{
			while (board[row][col])
			{
				if (board[row][col] == 'x')
					board[row][col] = 0;
				++col;
			}
		}
		++row;
	}
}
