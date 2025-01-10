/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkolani <bkolani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:14:42 by bkolani           #+#    #+#             */
/*   Updated: 2025/01/05 11:28:40 by bkolani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	*ft_append_str(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = ft_calloc(ft_strlen(*s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}

void	ft_copy_map(char **dest, char **src, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			while (dest[--i])
				free(dest[i]);
			free(dest);
			return ;
		}	
		i++;
	}
	dest[i] = NULL;
}

void	ft_free_tmp_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

size_t	ft_strlen_exclude_new_line(const char *str)
{
	if (!str || *str == '\0' || *str == '\n')
		return (0);
	return (1 + ft_strlen_exclude_new_line(str + 1));
}
