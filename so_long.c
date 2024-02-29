/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/29 11:42:50 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
// typedef struct s_list
// {
	
// }t_list;
// read map
// void	free_function(char **split, int	height)
// {
// 	int	i;
	
// 	i = 0;
// 	while (0 < height)
// 	{
// 		height--;
// 		free(split[height]);
// 		split[height] = NULL;
// 	}
// }
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
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[i] != '\0' || ss2[i] != '\0') && (n > i))
	{
		if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	if (n == i)
		return (0);
	return (ss1[i] - ss2[i]);
}

void	ft_print_error(char *str)
{
	if (ft_strncmp(str, "content", ft_strlen(str)) == 0)
		write(1, "eroor\ncontent", 13);
	if (ft_strncmp(str, "border", ft_strlen(str)) == 0)
		write(1, "eroor\nborder", 12);
	if (ft_strncmp(str, "arg", ft_strlen(str)) == 0)
		write(1, "eroor\nnumber of arguments invalid", 33);
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
		return (ft_print_error("arg"), 1); 
	fd = open(arg_v[1], O_RDONLY);
	if(fd < 0)
		return (close(fd), 1);
	bufer =	read_map(fd);
	if (!bufer)
		return(free(bufer), 1);
	//ayman
	l = 0;
	while (bufer[l] != '\0')
	{
		if ((bufer[l] != '1' && bufer[l] != '0' && bufer[l] != 'P' && bufer[l] != 'E' && bufer[l] != 'C' && bufer[l] != '\n'))
			{
				return (free(bufer), ft_print_error("content"),1);
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
	//************************************
	int t = handel_border(split, width, height);
	if (t == 1)
		return (ft_print_error("border"), 1);
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
