/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:03:30 by hben-laz          #+#    #+#             */
/*   Updated: 2024/02/29 11:30:50 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


char	*get_next_line(int fd);
int		count_word(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void	*dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	**my_array(char **array, char const *s, char c, int nbr_word);
char	**ft_split(char const *s, char c);
int		handel_border( char **split,int whidth, int height);
void	ft_print_error(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif