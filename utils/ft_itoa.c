/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:41:22 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/06 11:52:22 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*handle_zero_case(char *result)
{
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	long int	len;
	char		*result;
	long int	nbr;

	len = get_length(n);
	nbr = (long int)n;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	if (nbr == 0)
		return (handle_zero_case(result));
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	result[len] = '\0';
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (result);
}
