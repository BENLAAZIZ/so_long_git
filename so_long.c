/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/28 22:53:10 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
// typedef struct s_list
// {
	
// }t_list;
// read map
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
			return (free(buffer), printf("rrrrrr"), NULL);
	}
	return (buffer);
}
int main(int arg_c, char **arg_v)
{
	
	int		fd;
	int		l;
	int		width;
	int		height;
	char	*bufer;
	char	*s;
	char 	**split;
	void	*mlx_ptr;
	void	*mlx_win;

	if (arg_c != 2)
		return (printf("error nbr arg"), 1); 
	fd = open(arg_v[1], O_RDONLY);
	if(fd < 0)
		return (1);
	bufer =	read_map(fd);
	//ayman
	l = 0;
	while (bufer[l] != '\0')
	{
		if ((bufer[l] != '1' && bufer[l] != '0' && bufer[l] != 'P' && bufer[l] != 'E' && bufer[l] != 'C' && bufer[l] != '\n'))
			{
				return (1);
			}
		l++;
	}
	//ayamn final
	split = ft_split(bufer, '\n');
	char **temp  = split;
	// char **temp = split;
	if (!split)
		return (1);
	//whidth of first line
	width = ft_strlen(split[0]);
	height = count_word(bufer, '\n');
   	int i = 0;
	while(split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	// printf("width : %d\n", width);
	// printf("height : %d\n", height);
	//************************************
	int t = handel_border(split, width, height);
	if (t == 1)
		return (puts("error"), 1);
	//************************************
   //*************************************** amon zam*****
   int x = width;
	int y = height;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, x * 50, y * 50, "so_long");
	i = 0;
	int w;
	int h;
	void *avatar = mlx_xpm_file_to_image(mlx_ptr ,"textures/player.xpm",&w,&h);
	void *route = mlx_xpm_file_to_image(mlx_ptr ,"textures/route.xpm", &w, &h);
	void *wall = mlx_xpm_file_to_image(mlx_ptr ,"textures/wall_sijn1pxm.xpm", &w, &h);
	void *coin = mlx_xpm_file_to_image(mlx_ptr ,"coin.xpm", &w, &h);
	void *road = mlx_xpm_file_to_image(mlx_ptr ,"road.xpm", &w, &h);
	// char **split = ft_split(bufer, '\n');
	free(bufer);
	int j;
	while(temp[i])
	{
		j = 0;
		while(temp[i][j] != '\0')
		{
		puts("here");
			if(temp[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, mlx_win, wall, j * 50, i * 50);
			if(temp[i][j] == '0')
				mlx_put_image_to_window(mlx_ptr, mlx_win, route, j * 50, i * 50);
			if(temp[i][j] == 'P')
				mlx_put_image_to_window(mlx_ptr, mlx_win, avatar, j * 50, i * 50);
			if(temp[i][j] == 'E')
				mlx_put_image_to_window(mlx_ptr, mlx_win, road, j * 50, i * 50);
			if(temp[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, mlx_win, coin, j * 50, i * 50);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
	//******************************* fin amin zam ********************
	// mlx_put_image_to_window()
	return (0);
}
