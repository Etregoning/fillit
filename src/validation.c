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

void valid_piece(char *piece)
{

}

char  *trim_piece(char *piece)
{
  int i;
  int hash_count;
  char  *hash_ptr;

  i = 0;
  hash_count =  0;
  while (i++ < 20)
  {
    if (*piece == '#')
    {
        hash_count++;
        *hash_ptr = *piece;
    }

  }
}

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
