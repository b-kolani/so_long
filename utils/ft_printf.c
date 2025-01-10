/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:39:16 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 11:24:12 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	is_printf_fmt(char fmt)
{
	if (fmt == 'c' || fmt == 's' || fmt == 'p' || fmt == 'd' || fmt == 'i'
		|| fmt == 'u' || fmt == 'x' || fmt == 'X' || fmt == '%')
		return (1);
	return (0);
}

static int	check_fmt(va_list args, char fmt, int *len)
{
	int	temp;

	temp = 0;
	if (fmt == 'c')
		temp = ft_putchar_fd(va_arg(args, int), 1);
	else if (fmt == 's')
		temp = ft_putstr_fd(va_arg(args, char *), 1);
	else if (fmt == 'p')
		temp = ft_putptr(va_arg(args, size_t));
	else if (fmt == 'd' || fmt == 'i')
		temp = ft_putnbr_fd(va_arg(args, int), 1);
	else if (fmt == 'u')
		temp = ft_putunint_fd(va_arg(args, unsigned int), 1);
	else if (fmt == 'x' || fmt == 'X')
		temp = ft_puthex(va_arg(args, unsigned int), fmt);
	else if (fmt == '%')
		temp = ft_putchar_fd('%', 1);
	if (temp < 0)
		*len = -1;
	else
		*len += temp;
	return (*len);
}

static int	handle_fmt(const char *format, va_list args, int *len_ptr)
{
	int	i;
	int	len;

	i = 0;
	len = *len_ptr;
	while (format[i])
	{
		if (format[i] == '%' && is_printf_fmt(format[i + 1]))
		{
			len = check_fmt(args, format[i + 1], &len);
			if (len < 0)
				return (-1);
			i++;
		}
		else if (format[i] != '%')
		{
			len += ft_putchar_fd(format[i], 1);
			if (len < 0)
				return (-1);
		}
		i++;
	}
	*len_ptr = len;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	if (handle_fmt(format, args, &len) < 0)
	{
		va_end(args);
		return (-1);
	}
	va_end(args);
	return (len);
}
