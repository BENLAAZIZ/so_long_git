/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:03:30 by hben-laz          #+#    #+#             */
/*   Updated: 2024/03/08 21:50:04 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_piece
{
	void	*player;
	void	*rout;
	void	*wall;
	void	*door;
	void	*coin;
	int		pl;
	int		coi;
	int		dr;
	int		i;
	int		j;
}	t_piece;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	**split;
	int		x_p;
	int		y_p;
	int		width;
	int		height;
	t_piece	p;
}	t_data;

char	*get_next_line(int fd);
char	*read_map(int fd);
int		count_word(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	**my_array(char **array, char const *s, char c, int nbr_word);
char	**ft_split(char const *s, char c);
int		handel_border( char **split, int whidth, int height);
void	ft_print_error(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		handel_content(char	*bufer, t_data *data);
void	print_image(t_data *data);
int		handel_hey(int key, t_data *data);
void	cord_player(t_data *data);
void	move_p_up(t_data *data);
void	move_p_down(t_data *data);
void	move_p_right(t_data *data);
void	move_p_left(t_data *data);

#endif
