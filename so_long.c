/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/28 19:13:02 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
// typedef struct s_list
// {
	
// }t_list;

int	handel_border( char **split,int whidth, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
		//first line and last line
	while (x < whidth)
	{
		if (split[0][x] != '1' || split[height - 1][x] != '1')
			return (1);
		x++;
	}
	//first column and last column
	y = 0;
	while (y < height && split[y] != NULL)
	{
		if (split[y][0] != '1' || split[y][whidth - 1] != '1')
			return (1);
		if (ft_strlen(split[y]) != (size_t)whidth)
            return 1;
		y++;
	}
	return (0);
	
}

//  int	handel_content( char **split,int whidth, int height, int *p, int *e)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	// player
	
// 	printf("%s", split[0]);
// 	while (i < height)
// 	{
// 		while (j < whidth)
// 		{
// 			if (!(split[i][j] == '1' || split[i][j] == '0' || split[i][j] == 'P' || split[i][j] == 'E' || split[i][j] == 'C'))
// 				return (1);
// 			if (split[i][j] == 'P')
// 				(*p)++;
// 			if (split[i][j] == 'E')
// 				(*e)++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	//  collectible
// 	return (0);
// }


int main()
{
	
	int		fd;
	int		width;
	int		height;
	char	*bufer;
	char	*s;
	char 	**split;
	void	*mlx_ptr;
	void	*mlx_win;
	// int		p = 0;
	// int		e = 0;
	
	fd = open("maps.ber", O_RDONLY);
	if(fd < 0)
		return (1);
	
	s =get_next_line(fd);
	if(!s || s[0] != '1')
		return (printf("rrrrrr"), 1);
	while (s)
	{
		bufer =	ft_strjoin(bufer, s);
		s = get_next_line(fd);
		if (s && s[0] != '1')
			return (printf("rrrrrr"), 1);
		free(s);
	}
	//ayman
	int l = 0;
	while (bufer[l] != '\0')
	{
		if ((bufer[l] != '1' && bufer[l] != '0' && bufer[l] != 'P' && bufer[l] != 'E' && bufer[l] != 'C' && bufer[l] != '\n'))
			{
				printf("error");
				return (1);
			}
		l++;
	}
	//ayamn final
	split = ft_split(bufer, '\n');
	char **temp  = split;
	printf("{%s}", split[0]);
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
	
	printf("width : %d\n", width);
	printf("height : %d\n", height);
	//************************************
	int t = handel_border(split, width, height);
	if (t == 1)
	{
		printf("error \n border");
		exit(1);
	}
	//************************************
	// int p = 0;
	// int e = 0;
	// int u = handel_content(temp, width, height, &p, &e);
	// if (u == 1)
	// {
	// 	printf("error \n content");
	// 	exit(1);
	// }
   //*************************************** amon zam*****

   int x = 22;
	int y = 7;
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
