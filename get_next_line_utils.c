/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 19:54:06 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/08 19:54:22 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (*s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*c;
	size_t			i;

	i = 0;
	if (n == 0)
		return (dst);
	ptr = (unsigned char *)dst;
	c = (unsigned char *)src;
	if (ptr == NULL && c == NULL)
		return (dst);
	while (i < n)
	{
		*(ptr + i) = *(c + i);
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*tab;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	tab = (char *)malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (NULL);
	if (size > 0)
		ft_memcpy(tab, s1, size);
	tab[size] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	tab = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}
