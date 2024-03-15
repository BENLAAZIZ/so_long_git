/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_otils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:35:21 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/15 15:23:36 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_buffer(char **arg_v, t_data *data)
{
	int		fd;

	data->buffer = NULL;
	if (arg_v[1] != NULL)
	{
		fd = open(arg_v[1], O_RDONLY);
		if (fd < 0)
			return (NULL);
		data->buffer = read_map(fd);
		if (!data->buffer)
			return (close(fd), NULL);
		return (close(fd), data->buffer);
	}
	else
		return (free(data->buffer), NULL);
}

int	fload_fill(t_data *data, int x, int y, int *exit)
{
	if (data->split[x][y] == '1')
		return 0;
	if (data->split[x][y] == 'E' && data->p.coi_copy == 0)
	{
		data->split[x][y] = '1';
		--(*exit);
	}
	if (data->split[x][y] == 'E' && data->p.coi_copy > 0)
			return 0;
	if (data->split[x][y] == 'C')
		--data->p.coi_copy;
	data->split[x][y] = '1';
	fload_fill(data, (x - 1), y, exit);
	fload_fill(data, (x + 1), y, exit);
	fload_fill(data, x, (y - 1), exit);
	fload_fill(data, x, (y + 1), exit);
	if (data->p.coi_copy <= 0 && *exit <= 0)
		return (1);
	return (0);
}

// int	f_fload(t_data *data)
// {
// 	int	i;
// 	int	j;

// 	j = 0;
// 	while (data->split2[j] != NULL)
// 	{
// 		i = 0;
// 		while (data->split2[j][i] != '\0')
// 		{
// 			if (data->split2[j][i] == '0')
// 				return (0);
// 			i++;
// 		}
// 		// printf("\n%s", data->split2[j]);
// 		j++;
// 	}
// 	return (1);
// }

// void	free_data(t_data *data)
// {
// 	if (!data)
// 		return ;
// 	mlx_destroy_image(data->mlx_ptr, data->p.player);
// }

void free_t_data(char **array)
{
	int i;

	i = 0;
	if(!array)
		return ;
	while(array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}