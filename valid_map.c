/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:19:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/05 16:50:54 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd)
{
	char	*s;
	char	*buffer;
	char	*tmp;

	s = "   ";
	buffer = NULL;
	while (s)
	{
		s = get_next_line(fd);
		tmp = buffer;
		buffer = ft_strjoin(buffer, s);
		free(tmp);
		free(s);
		if (s && s[0] != '1')
			return (free(buffer), ft_print_error("border"), NULL);
	}
	return (buffer);
}
int	handel_border( char **split,int whidth, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < whidth)
	{
		if (split[0][x] != '1' || split[height - 1][x] != '1')
			return (ft_print_error("border"), 1);
		x++;
	}
	y = 0;
	while (y < height && split[y] != NULL)
	{
		if (split[y][0] != '1' || split[y][whidth - 1] != '1')
			return (ft_print_error("border"), 1);
		if (ft_strlen(split[y]) != (size_t)whidth)
            return (ft_print_error("border"), 1);
		y++;
	}
	return (0);
	
}
int	handel_content(char	*bufer)
{
		int i = 0;
	
	while (bufer[i] != '\0')
	{
		if ((bufer[i] != '1' && bufer[i] != '0' && bufer[i] != 'P' && bufer[i] != 'E' && bufer[i] != 'C' && bufer[i] != '\n'))
			{
				return (1);
			}
		i++;
	}
	return (0);
}
