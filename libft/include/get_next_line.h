/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iazmi <iazmi@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:05:51 by iazmi             #+#    #+#             */
/*   Updated: 2024/06/04 17:26:24 by iazmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				get_nl_index(char *text);
int				reader_fn(int fd, char *value);
int				fill_buffer_fn(int fd, char **buffer);
char			*parse_buffer(char **buffer, int eof);
char			*get_next_line(int fd);

char			*buffer_util(char **buffer, int tofree);
char			*str_append_safe(char *dest, char *src);
int				str_len(char *src);
void			str_cpy(char *dest, char *src);
void			str_cat(char *dest, char *src);

#endif