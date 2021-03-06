/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:21:37 by etregoni          #+#    #+#             */
/*   Updated: 2017/04/19 01:18:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*createtet3(int tet, char *str)
{
	if (tet == 9)
		return (ft_strcpy(str, "##...#...#"));
	else if (tet == 10)
		return (ft_strcpy(str, "##..##"));
	else if (tet == 11)
		return (ft_strcpy(str, ".##.##"));
	else if (tet == 12)
		return (ft_strcpy(str, "#...##...#"));
	else if (tet == 13)
		return (ft_strcpy(str, ".#..###"));
	else if (tet == 14)
		return (ft_strcpy(str, "#...##..#"));
	else if (tet == 15)
		return (ft_strcpy(str, "###..#"));
	else if (tet == 16)
		return (ft_strcpy(str, ".#..##...#"));
	else if (tet == 17)
		return (ft_strcpy(str, "##...##"));
	return (ft_strcpy(str, ".#..##..#"));
}

char	*createtet2(int tet)
{
	char	*str;

	if (!(str = ft_strnew(20)))
		return (0);
	if (tet == 0)
		return (ft_strcpy(str, "####"));
	else if (tet == 1)
		return (ft_strcpy(str, "#...#...#...#"));
	else if (tet == 2)
		return (ft_strcpy(str, "#...###"));
	else if (tet == 3)
		return (ft_strcpy(str, "##..#...#"));
	else if (tet == 4)
		return (ft_strcpy(str, "###...#"));
	else if (tet == 5)
		return (ft_strcpy(str, ".#...#..##"));
	else if (tet == 6)
		return (ft_strcpy(str, "..#.###"));
	else if (tet == 7)
		return (ft_strcpy(str, "#...#...##"));
	else if (tet == 8)
		return (ft_strcpy(str, "###.#"));
	else
		return (createtet3(tet, str));
}

char	**create_tet(int *index)
{
	char	**tet;
	int		size;
	int		i;

	size = 0;
	while (index[size] != 42)
		size++;
	if (!(tet = (char **)malloc(sizeof(char *) * (size + 1))))
		return (0);
	tet[size] = 0;
	i = 0;
	while (index[i] != 42)
	{
		if (!(tet[i] = createtet2(index[i])))
		{
			tbldel(tet);
			return (0);
		}
		i++;
	}
	return (convert_array(tet));
}
