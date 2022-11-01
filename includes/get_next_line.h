/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkanmado <rkanmado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:11:07 by rkanmado          #+#    #+#             */
/*   Updated: 2022/11/01 06:11:10 by rkanmado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl
{
	char	*line;
	int		i;
	int		j;
	char	*buff_cpy;
	char	*next_buffer;
}	t_gnl;

char	*get_next_line(int fd);
char	*ft_next_line(t_gnl *t_gnl);
void	ft_get_line(char *buffer, t_gnl *t_gnl);
char	*ft_read(char *res, int fd);
size_t	ft_strlen_gnl(char *s);
char	*ft_strcat_gnl(char *s1, char *s2);
char	*ft_strcpy_gnl(char *dst, char *src);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, int c);
void	init_var(t_gnl *t_gnl);

#endif
