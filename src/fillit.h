/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:21:46 by etregoni          #+#    #+#             */
/*   Updated: 2017/03/22 19:21:49 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define VALID(k, j) {ret[k] = j; k++; j = 0; break;} j++
# include "../libft/libft.h"
# include <fcntl.h>

void	puttbl(char **tbl);
void	tbldel(char **tbl);
char	**tblnew(int len, int str_len);
int		tbl_trim(char **src_tbl);
void	assign_tbl(char **src_tbl, char *src);
void	valid_char(char *src, int *src_len, int *lines);
int		validate_count(char *src, int *blck_cnt);
int		*validate_pattern(char **src_tbl);
int		board_size(int *index);
char	**create_board(int size, int str_size);
char	**create_tet(int *index);
int		recursor(char **board, char **tet, int row, int col);
void	cleanup_board(char **board);
char	**convert_array(char **tet);
int		*nbr_str_new(int size, int stop);

#endif
