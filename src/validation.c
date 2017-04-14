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
#include <stdio.h>
// void validate_v(char *piece)
// }
//   int adj;
//
//   adj = 0;
// }

void validate_h(char *piece)
{
  int adj;
  int count;

  adj = 0;
  count = 0;
  while (count++ < 20)
  {
    if (*piece == '#')
    {
      printf(GREEN "X" RESET);
      piece++;
      if (*piece == '#')
      {
        printf(GREEN "X" RESET);
        adj++;
      }
      if (adj == 3)
        while (count++ < 20)
        {
          if (*piece == '#')
            ft_error();
          else
            printf(RED "_" RESET);
          piece++;
        }
    }
    else if (*piece == '.')
    {
        printf(RED "_" RESET);
        piece++;
    }
    else if (*piece == '\n')
      {
        printf("\n");
        piece++;
      }
  }
}

int     num_pieces(char *fillit)
{
  char *piece;
  int bsize;
  int fd;

  piece = ft_memalloc(546);
  bsize = 0;
  fd = open(fillit, O_RDONLY);
  while (read(fd, piece, 1))
    if (*piece == '.' || *piece == '#' || *piece == '\n')
      bsize++;
  if (bsize > 545)
    ft_error();
  close (fd);
  return (bsize / 21 + 1);
}
