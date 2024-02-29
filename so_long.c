/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/29 12:38:18 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
typedef struct s_piece
{
	void *avatar;
	void *route;
	void *wall;
	void *coin;
	void *road;
	
}t_piece;
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

void	put_image(char **temp, void *mlx_ptr, void *mlx_win, t_piece *p)
{
	int		j;
	int		i;
	
	i = 0;
	while(temp[i])
	{
		j = 0;
		while(temp[i][j] != '\0')
		{
			puts("here");
			if(temp[i][j] == '1')
				mlx_put_image_to_window(mlx_ptr, mlx_win, p->wall, j * 50, i * 50);
			if(temp[i][j] == '0')
				mlx_put_image_to_window(mlx_ptr, mlx_win, p->route, j * 50, i * 50);
			if(temp[i][j] == 'P')
				mlx_put_image_to_window(mlx_ptr, mlx_win, p->avatar, j * 50, i * 50);
			if(temp[i][j] == 'E')
				mlx_put_image_to_window(mlx_ptr, mlx_win, p->road, j * 50, i * 50);
			if(temp[i][j] == 'C')
				mlx_put_image_to_window(mlx_ptr, mlx_win, p->coin, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

// char	*funct1()
// {
	
// }

int main(int arg_c, char **arg_v)
{
	
	int		fd;
	int		width;
	int		height;
	char	*bufer;
	char	*s;
	char 	**split;
	void	*mlx_ptr;
	void	*mlx_win;
	int 	i;
	int		t;
	t_piece p;

	if (arg_c != 2)
		return (ft_print_error("arg"), 1); 
	fd = open(arg_v[1], O_RDONLY);
	if(fd < 0)
		return (close(fd), 1);
	bufer =	read_map(fd);
	if (!bufer)
		return(free(bufer), 1);
	//ayman
	i = 0;
	while (bufer[i] != '\0')
	{
		if ((bufer[i] != '1' && bufer[i] != '0' && bufer[i] != 'P' && bufer[i] != 'E' && bufer[i] != 'C' && bufer[i] != '\n'))
			{
				return (free(bufer), ft_print_error("content"),1);
			}
		i++;
	}
	//ayamn final
	split = ft_split(bufer, '\n');
	char **temp  = split;
	if (!split)
		return (1);
	//whidth of first line
	width = ft_strlen(split[0]);
	height = count_word(bufer, '\n');
	//************************************
	t = handel_border(split, width, height);
	if (t == 1)
		return (ft_print_error("border"), 1);
	//************************************
    int x = width;
	int y = height;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, x * 50, y * 50, "so_long");
	int w;
	int h;
	p.avatar = mlx_xpm_file_to_image(mlx_ptr ,"textures/player.xpm",&w,&h);
	p.route = mlx_xpm_file_to_image(mlx_ptr ,"textures/route.xpm", &w, &h);
	p.wall = mlx_xpm_file_to_image(mlx_ptr ,"textures/wall_sijn1pxm.xpm", &w, &h);
	p.coin = mlx_xpm_file_to_image(mlx_ptr ,"coin.xpm", &w, &h);
	p.road = mlx_xpm_file_to_image(mlx_ptr ,"road.xpm", &w, &h);
	free(bufer);
	put_image(temp, mlx_ptr, mlx_win, &p);
	mlx_loop(mlx_ptr);
	return (0);
}
