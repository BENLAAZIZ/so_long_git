/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_otils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:35:21 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/18 03:33:59 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(int fd)
{
	char	*s;
	char	*buffer;
	char	*tmp;

	buffer = NULL;
	tmp = NULL;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		tmp = buffer;
		buffer = ft_strjoin(tmp, s);
		free(tmp);
		free(s);
		s = NULL;
	}
	if (!buffer)
		return (NULL);
	return (buffer);
}

void	*ft_mlx_xpm_file_to_image(t_data *data, char *path)
{
	int		h;
	int		w;
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &h, &w);
	if (!img)
		return (NULL);
	return (img);
}

char	*get_buffer(char **arg_v, t_data *data)
{
	int		fd;

	data->buffer = NULL;
	if (ft_filename(arg_v[1]))
		return (NULL);
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
		return (0);
	if (data->split[x][y] == 'E' && data->p.coi_copy == 0)
	{
		data->split[x][y] = '1';
		--(*exit);
	}
	if (data->split[x][y] == 'E' && data->p.coi_copy > 0)
		return (0);
	if (data->split[x][y] == 'C')
		--data->p.coi_copy;
	data->split[x][y] = '1';
	fload_fill(data, (x - 1), y, exit);
	fload_fill(data, (x + 1), y, exit);
	fload_fill(data, x, (y - 1), exit);
	fload_fill(data, x, (y + 1), exit);
	if (data->p.coi_copy <= 0 && *exit <= 0)
		return (0);
	return (1);
}

int	handel_key(int key, t_data *data)
{
	if (key == 53)
	{
		free_t_split(data->split2);
		exit(1);
	}
	if (key == 13 || key == 126)
	{
		move_p_up(data);
	}
	if (key == 1 || key == 125)
	{
		move_p_down(data);
	}
	if (key == 2 || key == 124)
	{
		move_p_right(data);
	}
	if (key == 0 || key == 123)
	{
		move_p_left(data);
	}
	return (1);
}
