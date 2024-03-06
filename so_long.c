/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/06 16:58:21 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
char *get_image_path(int c)
{
	char *path_img;
	path_img = NULL;
	if(c == 'P')
		path_img = "textures/player.xpm";
	else if(c == '0')
		path_img = "textures/route.xpm";
	else if(c == '1')
		path_img = "textures/wall_sijn1pxm.xpm";
	else if(c == 'E')
		path_img = "textures/door.xpm";
	else if(c == 'C')
		path_img = "textures/tassarott.xpm";
	return (path_img);	
}
void print_image(char **split, t_data data)
{
	int	i;
	int	j;
	int	w;
	int	h;

	w = 50;
	h = 50;
	i = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr =mlx_new_window(data.mlx_ptr, data.width * 50, data.height * 50, "./so-long");
	while(i < data.height)
	{
		j = 0;
		while(j < data.width)
		{
			data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr , get_image_path(split[i][j]), &w, &h);
			mlx_put_image_to_window(data.mlx_ptr,data.win_ptr, data.img_ptr, j * 50, i * 50);
			j++;
		}
		i++;
	}
	mlx_loop(data.mlx_ptr);
}
int main(int arg_c, char **arg_v)
{
	int		fd;
	char	*bufer;
	char 	**split;
	t_data	data;

	if (arg_c != 2)
		return (ft_print_error("arg"), 1); 
	fd = open(arg_v[1], O_RDONLY);
	if(fd < 0)
		return (close(fd), 1);
	bufer =	read_map(fd);
	if (!bufer)
		return(free(bufer), close(fd), 1);
	if (handel_content(bufer) == 1)
		return (free(bufer), close(fd), ft_print_error("content"),1);
	split = ft_split(bufer, '\n');
	if (!split)
		return (free(bufer), close(fd), 1);
	data.width = ft_strlen(split[0]);
	data.height = count_word(bufer, '\n');
	if ((handel_border(split, data.width, data.height)) == 1)
		return (free(bufer), close(fd), 1);
	print_image(split, data);
	return (0);
}
