/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/27 19:12:51 by hben-laz         ###   ########.fr       */
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

 int	handel_content( char **split,int whidth, int height, int *p, int *e)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	// player
	while (i < height)
	{
		while (j < whidth)
		{
			if (split[i][j] != '1' && split[i][j] != '0' && split[i][j] != 'P' && split[i][j] != 'E' && split[i][j] != 'C')
				return (1);
			if (split[i][j] == 'P')
				(*p)++;
			if (split[i][j] == 'E')
				(*e)++;
			j++;
		}
		i++;
	}
	//  collectible
	return (0);
}


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
		return (1);
	while (s)
	{
		bufer =	ft_strjoin(bufer, s);
		s = get_next_line(fd);
		if (s && s[0] != '1')
			return (printf("rrrrrr"), 1);
		free(s);
	}
	
	split = ft_split(bufer, '\n');
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
	int p = 0;
	int e = 0;
	int u = handel_content(split, width, height, &p, &e);
	if (u == 1)
	{
		printf("error \n content");
		exit(1);
	}
    mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, width * 50, height * 70, "./so_long");
	mlx_loop(mlx_ptr);

	// mlx_put_image_to_window()
	return (0);
}
