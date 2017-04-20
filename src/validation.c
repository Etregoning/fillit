/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <etregoni@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 19:21:46 by etregoni          #+#    #+#             */
/*   Updated: 2017/03/22 19:21:49 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_compare(void)
{
	char	**ret;

	if (!(ret = tblnew(19, 13)))
		return (0);
	ret[0] = "####";
	ret[1] = "#...#...#...#";
	ret[2] = "#...###";
	ret[3] = "##..#...#";
	ret[4] = "###...#";
	ret[5] = "#...#..##";
	ret[6] = "#.###";
	ret[7] = "#...#...##";
	ret[8] = "###.#";
	ret[9] = "##...#...#";
	ret[10] = "##..##";
	ret[11] = "##.##";
	ret[12] = "#...##...#";
	ret[13] = "#..###";
	ret[14] = "#...##..#";
	ret[15] = "###..#";
	ret[16] = "#..##...#";
	ret[17] = "##...##";
	ret[18] = "#..##..#";
	return (ret);
}

int		*validate_pattern(char **src_tbl)
{
	int		*ret;
	char	**compare;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if ((!(ret = nbr_str_new(26, 42))) ||
			(!(compare = create_compare())))
		return (0);
	while (src_tbl[i])
	{
		while (compare[j])
		{
			if (ft_strequ(src_tbl[i], compare[j]))
				VALID(k, j);
		}
		if (j == 0)
			i++;
		else
			return (0);
	}
	return (ret);
}

int		check(int *a, int *b)
{
	if (*a != 4)
		return (1);
	else
	{
		*a = 0;
		(*b)++;
		return (0);
	}
}

int		validate_count(char *src, int *blck_cnt)
{
	int		i;
	int		dots;
	int		lines;

	i = 0;
	dots = 0;
	lines = 0;
	if (src[i] == '\n')
		return (1);
	while (src[i])
	{
		if (src[i] == '.' || src[i] == '#')
			dots++;
		if (src[i] == '\n' && (src[i - 1] == '.' || src[i - 1] == '#'))
			if (check(&dots, &lines))
				return (1);
		if (src[i] == '\n' && (src[i + 1] == '\n' || src[i + 1] == '\0'))
			if (check(&lines, blck_cnt))
				return (1);
		i++;
	}
	return (0);
}

void	valid_char(char *src, int *src_len, int *lines)
{
	int		i;

	i = 0;
	while (*src)
	{
		if (*src != '.' && *src != '#' && *src != '\n')
		{
			*src_len = 1;
			return ;
		}
		if (*src == '\n')
			(*lines)++;
		src++;
		(*src_len)++;
	}
}
