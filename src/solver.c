/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:21:37 by etregoni          #+#    #+#             */
/*   Updated: 2017/04/18 01:18:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	remove_tet(char **board, char *tet)
{
	char	tmp;
	int		row;
	int		col;

	row = 0;
	while (*tet == '.')
		++tet;
	tmp = *tet;
	while (board[row])
	{
		col = 0;
		while (board[row][col])
		{
			if (board[row][col] == tmp)
				board[row][col] = '.';
			++col;
		}
		++row;
	}
}

void	write_tet(char **board, char *tet, int row, int col)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (tet[i])
	{
		if (tet[i] != '.')
			board[row][col] = tet[i];
		++i;
		++col;
		++cnt;
		if (cnt == 4)
		{
			++row;
			col -= 4;
			cnt = 0;
		}
	}
}

int		check_tet(char **board, char *tet, int row, int col)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (tet[i])
	{
		if (cnt == 4)
		{
			row++;
			cnt = 0;
			col -= 4;
		}
		if (tet[i] >= 'A' && tet[i] <= 'Z' && board[row][col] != '.')
			return (0);
		cnt++;
		col++;
		i++;
	}
	return (1);
}

int		recursor(char **board, char **tet, int row, int col)
{
	if (!*tet)
		return (0);
	while (board[row])
	{
		while (board[row][col])
		{
			if (check_tet(board, *tet, row, col))
			{
				write_tet(board, *tet, row, col);
				if (recursor(board, (1 + tet), 0, 0))
					remove_tet(board, *tet);
				else
					return (0);
			}
			++col;
		}
		++row;
		col = 0;
	}
	return (1);
}
