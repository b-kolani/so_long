/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:15:14 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 11:25:34 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_int_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	len;

	if (n == -2147483648)
	{
		if (ft_putstr_fd("-2147483648", fd) < 0)
			return (-1);
		return (11);
	}
	len = ft_int_len(n);
	if (n < 0)
	{
		if (ft_putchar_fd('-', fd) < 0)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		if (ft_putnbr_fd(n / 10, fd) < 0)
			return (-1);
	}
	if (ft_putchar_fd(n % 10 + '0', fd) < 0)
		return (-1);
	return (len);
}
