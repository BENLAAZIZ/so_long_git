/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:19:00 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/20 05:43:55 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (ft_strlen(split[y]) != (size_t)whidth)
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

void	init_variable(t_data *data)
{
	data->p.coi = 0;
	data->p.coin = 0;
	data->p.dr = 0;
	data->p.coi = 0;
	data->p.a = 1;
}

int	handel_content(char	*bufer, t_data *data)
{
	int	i;

	i = 0;
	init_variable(data);
	if (!bufer || !bufer[i])
		return (1);
	while (bufer[i] != '\0')
	{
		if ((bufer[i] != '1' && bufer[i] != '0' && bufer[i] != 'P'
				&& bufer[i] != 'E' && bufer[i] != 'C' && bufer[i] != '\n'))
			return (1);
		if (bufer[i] == '\n' && bufer[i + 1] == '\n')
			return (1);
		if (bufer[i] == 'P')
			data->p.pl++;
		if (bufer[i] == 'E')
			data->p.dr++;
		if (bufer[i] == 'C')
			data->p.coi++;
		i++;
	}
	free(data->buffer);
	return (check_piece(data->p.pl, data->p.dr, data->p.coi));
}

int	ft_filename(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (1);
	while (file[i])
		i++;
	--i;
	if (file[i - 4] == '/')
		return (1);
	if (file[i] != 'r' || file[i - 1] != 'e'
		|| file[i - 2] != 'b' || file[i - 3] != '.')
		return (1);
	return (0);
}
