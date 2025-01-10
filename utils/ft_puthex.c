/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:47:00 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 11:25:07 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	print_hex(unsigned int n, char *base)
{
	char	string[25];
	int		i;
	int		len;
	int		tmp;

	i = 0;
	len = 0;
	while (n != 0)
	{
		string[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
	{
		tmp = ft_putchar_fd(string[i], 1);
		if (tmp < 0)
			return (-1);
		len += tmp;
	}
	return (len);
}

int	ft_puthex(unsigned int n, char a)
{
	char	base[17];
	int		len;
	int		result;

	if (a == 'X')
		ft_strlcpy(base, "0123456789ABCDEF", sizeof(base));
	else
		ft_strlcpy(base, "0123456789abcdef", sizeof(base));
	if (n == 0)
	{
		result = ft_putchar_fd('0', 1);
		if (result < 0)
			return (-1);
		return (result);
	}
	result = print_hex(n, base);
	if (result < 0)
		return (-1);
	len = result;
	return (len);
}
