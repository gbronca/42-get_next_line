/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:17:31 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/11/02 15:26:10 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// read()
# include <unistd.h>
// free() & malloc()
# include <stdlib.h>
// BUFSIZ
# include <stdio.h>

// Read buffer: buffer[start .. len]
typedef struct s_state
{
	char		*buffer;
	size_t		start;
	size_t		len;
}	t_state;

// The line being built
typedef struct s_line
{
	char		*str;
	size_t		len;
	size_t		capacity;
}	t_line;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

char	*get_next_line(int fd);
int		gnl_read_fd(int fd, t_state *state);
int		gnl_append(t_line *line, const char *src, size_t n);
void	gnl_free(t_state *state);

#endif
