/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:02:37 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/26 21:45:33 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
typedef struct s_list
{
	
}t_list;

int	handel_border( char **split,int whidth, int height)
{
	int	i;

	i = 0;
		//first line and last line
	while (i < whidth)
	{
		if (split[0][i] != 1 || split[height][i] != 1)
			return 1;
		i++;
	}
	if (split[0][i])
	//first column and last column
	i = 0;
	while (i < height)
	{
		if (split[i][0] != 1 || split[i][whidth] != 1)
			return 1;
		i++;
	}
	return (0);
}

// int	handel_content( char **split,int whidth, int height)
// {
// 	// int	y;
// 	int	x;
// 	int	p;
// 	int	e;
// 	// player
// 	while (y < height)
// 	{
// 		while (x < whidth)
// 		{
// 			if (split[0][x] == 'P')
// 				p++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	//  collectible,
// 	while (y < height)
// 	{
// 		while (x < whidth)
// 		{
// 			if (split[0][x] == 'E')
// 				e++;
// 			x++;
// 		}
// 		y++;
// 	}
// }


int main()
{
	
	int		fd;
	int		width;
	char	*bufer;
	char	*s;
	char 	**split;
	void	*mlx_ptr;
	void	*mlx_win;
	
	fd = open("maps.ber", O_RDONLY);
	if(fd < 0)
		return (1);
	
	s =get_next_line(fd);
	if(!s)
			return (1);
	while (s)
	{
		bufer =	ft_strjoin(bufer, s);
		s = get_next_line(fd);
		free(s);
	}
	
	split = ft_split(bufer, '\n');
	if (!split)
		return (1);
	width = ft_strlen(split[0]);
    int i = 0;
	int height = count_word(bufer, '\n');
	while(split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	
	printf("width : %d\n", width);
	printf("height : %d\n", height);
    mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, width * 70, height * 70, "./so_long");
	mlx_loop(mlx_ptr);

	// mlx_put_image_to_window()
	return (0);
}
