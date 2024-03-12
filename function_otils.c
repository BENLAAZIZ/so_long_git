/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_otils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:35:21 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/12 17:36:11 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_buffer(char **arg_v)
{
	int		fd;
	char	*buffer;

	if (arg_v[1] != NULL)
	{
		fd = open(arg_v[1], O_RDONLY);
		if (fd < 0)
			return (NULL);
		buffer = read_map(fd);
		if (!buffer)
			return (free(buffer), NULL);
		return (buffer);
	}
	else
		return (NULL);
	}