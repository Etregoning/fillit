/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etregoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:21:37 by etregoni          #+#    #+#             */
/*   Updated: 2017/03/10 01:18:56 by etregoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# define BOOL int
# define TRUE 1
# define FALSE 0
# define RED		"\x1b[31m"
# define GREEN	"\x1b[32m"
# define YELLOW	"\x1b[33m"
# define BLUE		"\x1b[36m"
#define RESET		"\x1b[0m"


void			ft_putchar(char c);
void			ft_putstr(const char *s);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
int				ft_strequ(const char *s1, const char *s2);
void			ft_putendl(const char *s);
void      *ft_memset(void *s, int c, size_t n);
int				ft_error(void);

#endif
