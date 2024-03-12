/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:19:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/12 14:08:20 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *str)
{
	if (ft_strncmp(str, "map", ft_strlen(str)) == 0)
		write(1, "Eroor\ninvalid map", 17);
	if (ft_strncmp(str, "arg", ft_strlen(str)) == 0)
		write(1, "Eroor\nnumber of arguments invalid", 33);
}

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
	return (close(fd), buffer);
}

int	handel_border( char **split, int whidth, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < whidth)
	{
		if (split[0][x] != '1' || split[height - 1][x] != '1')
			return (ft_print_error("map"), 1);
		x++;
	}
	y = 0;
	while (y < height)
	{
		if (split[y][0] != '1' || split[y][whidth - 1] != '1')
				return (ft_print_error("map"), 1);
		if (ft_strlen(split[y]) != whidth)
			return (ft_print_error("map"), 1);
		y++;
	}
	return (0);
}

static int	check_piece(int pl, int dr, int coi)
{
	if (pl != 1 || dr != 1 || coi < 1)
		return (1);
	return (0);
}

int	handel_content(char	*bufer, t_data *data)
{
	int	i;

	i = 0;
	data->p.coi = 0;
	data->p.coin = 0;
	data->p.dr = 0;
	data->p.coi = 0;
	if (!bufer[i])
		return (ft_print_error("map"), 1);
	while (bufer[i] != '\0')
	{
		if ((bufer[i] != '1' && bufer[i] != '0' && bufer[i] != 'P'
				&& bufer[i] != 'E' && bufer[i] != 'C' && bufer[i] != '\n'))
			return (ft_print_error("map"), 1);
		if (bufer[i] == '\n' && bufer[i + 1] == '\n')
			return (ft_print_error("map"), 1);
		if (bufer[i] == 'P')
			data->p.pl++;
		if (bufer[i] == 'E')
			data->p.dr++;
		if (bufer[i] == 'C')
			data->p.coi++;
		i++;
	}
	return (check_piece(data->p.pl, data->p.dr, data->p.coi));
}
