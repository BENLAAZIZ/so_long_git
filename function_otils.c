/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_otils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:35:21 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/12 17:54:49 by hben-laz         ###   ########.fr       */
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

int	fload_fill(t_data *data, int x, int y, int *exit)
{
	if (data->split2[x][y] == '1')
		return 0;
	if (data->split2[x][y] == 'E' && data->p.coi_copy == 0)
	{
		data->split2[x][y] = '1';
		--(*exit);
	}
	// if (data->split2[x][y] == 'E' && data->p.coi_copy > 0)
	// 		return 0;
	if (data->split2[x][y] == 'C')
		--data->p.coi_copy;
	data->split2[x][y] = '1';
	fload_fill(data, (x - 1), y, exit);
	fload_fill(data, (x + 1), y, exit);
	fload_fill(data, x, (y - 1), exit);
	fload_fill(data, x, (y + 1), exit);
	if (data->p.coi_copy <= 0 && *exit <= 0)
		return (1);
	return (0);
}

int	f_fload(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->split2[j] != NULL)
	{
		i = 0;
		while (data->split2[j][i] != '\0')
		{
			if (data->split2[j][i] == '0')
				return (0);
			i++;
		}
		// printf("\n%s", data->split2[j]);
		j++;
	}
	return (1);
}