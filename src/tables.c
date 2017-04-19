/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tables.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:21:37 by etregoni          #+#    #+#             */
/*   Updated: 2017/04/18 01:18:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fillit.h"

char	**ft_tblnew(int len, int str_len)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		if (!(new[i] = ft_strnew(str_len)))
		{
			ft_tbldel(new);
			return (0);
		}
		i++;
	}
	new[i] = 0;
	return (new);
}

void	ft_puttbl(char **tbl)
{
	size_t	i;

	i = 0;
	while (tbl[i])
	{
		ft_putendl(tbl[i]);
		i++;
	}
}

void	ft_tbldel(char **tbl)
{
	size_t	i;

	i = 0;
	while (tbl[i])
	{
		free(tbl[i]);
		++i;
	}
	free(tbl);
	tbl = 0;
}
