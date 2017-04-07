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
  char *file;
  char *str;

  file = argv[1];
  str = (char*)malloc(sizeof(char) * 21);
  if (argc != 2)
  {
      ft_putstr("usage: ./fillit text_file\n");
      exit (1);
        return (1);
  }
  fd = open(file, O_RDONLY);
  read(fd, str, 20);
  str[20] = 0;
  printf("%s\n", str);
}
