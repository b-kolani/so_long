/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:22:41 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 12:03:27 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "unistd.h"
# include "stdlib.h"
# include "stdarg.h"
# include "stddef.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_puthex(unsigned int n, char a);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunint_fd(unsigned int n, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		ft_putptr(size_t addr);

#endif