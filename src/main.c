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

int     main(int argc, char **argv)
{
  int fd;
  char *fillit;
  char *piece;

  fillit = argv[1];
  piece = ft_memalloc(21);
  if (argc != 2)
  {
      ft_putstr("usage: ./fillit text_file\n");
      exit (1);
      return (1);
  }
  num_pieces(fillit);
  printf("number of pieces is: %d\n", num_pieces(fillit));
  fd = open(fillit, O_RDONLY);
  while (read(fd, piece, 21))
    validate_h(piece);
  return (0);
}
