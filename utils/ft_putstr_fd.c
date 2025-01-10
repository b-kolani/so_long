/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:47:09 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 11:26:00 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;
	int	tmp;

	tmp = 0;
	len = 0;
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	i = -1;
	while (s[++i])
	{
		tmp = ft_putchar_fd(s[i], fd);
		if (tmp < 0)
			return (-1);
		len += tmp;
	}
	return (len);
}
