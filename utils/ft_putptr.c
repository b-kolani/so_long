/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:46:50 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 11:43:00 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	print_ptr_addr(size_t addr, char *base)
{
	char	string[25];
	int		i;
	int		len;
	int		temp;

	i = 0;
	len = 0;
	while (addr != 0)
	{
		string[i++] = base[addr % 16];
		addr = addr / 16;
	}
	while (i--)
	{
		temp = ft_putchar_fd(string[i], 1);
		if (temp < 0)
			return (-1);
		len += temp;
	}
	return (len);
}

int	ft_putptr(size_t addr)
{
	int		len;
	int		result;

	if (write(1, "0x", 2) < 0)
		return (-1);
	len = 2;
	if (addr == 0)
	{
		if (write(1, "0", 1) < 0)
			return (-1);
		len++;
	}
	else
	{
		result = print_ptr_addr(addr, "0123456789abcdef");
		if (result < 0)
			return (-1);
		len += result;
	}
	return (len);
}
