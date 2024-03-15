/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:50:31 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/15 17:04:20 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_t_split(char **array)
{
	int i;

	i = 0;
	if(!array)
		return ;
	while(array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int ft_exit(t_data *data)
{
	free_t_split(data->split2);
	exit(1);
}

void	free_split_buffer(t_data *data)
{
	free_t_split(data->split);
	free(data->buffer);	
}

void	ft_print_error(char *str)
{
	if (ft_strncmp(str, "map", ft_strlen(str)) == 0)
		write(1, "Eroor\ninvalid map", 17);
	if (ft_strncmp(str, "arg", ft_strlen(str)) == 0)
		write(1, "Eroor\nnumber of arguments invalid", 33);
}