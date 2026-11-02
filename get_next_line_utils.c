/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:25:44 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/11/02 15:04:41 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Reads the next chunk of data into the state's buffer, allocating it on first
use. Returns 1 when bytes arrived, 0 at end of file, -1 on error.
return (bytes > 0) is the same as:
if (bytes > 0)
    return (1);
return (0);
*/
int	gnl_read_fd(int fd, t_state *state)
{
	ssize_t	bytes;

	if (!state->buffer)
	{
		state->buffer = malloc(BUFFER_SIZE);
		if (!state->buffer)
			return (-1);
	}
	bytes = read(fd, state->buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (-1);
	state->start = 0;
	state->len = bytes;
	return (bytes > 0);
}

static void	gnl_copy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
Appends n bytes to the line, doubling its capacity when they do not fit.
Building a line of any length on average copies each byte a constant number
of times. 
Returns 0 when the allocation fails, 1 otherwise.
*/
int	gnl_append(t_line *line, const char *src, size_t n)
{
	char	*tmp;
	size_t	capacity;

	if (line->len + n + 1 > line->capacity)
	{
		capacity = line->capacity;
		if (capacity == 0)
			capacity = 64;
		while (capacity < line->len + n + 1)
			capacity *= 2;
		tmp = malloc(capacity);
		if (!tmp)
			return (0);
		gnl_copy(tmp, line->str, line->len);
		free(line->str);
		line->str = tmp;
		line->capacity = capacity;
	}
	gnl_copy(line->str + line->len, src, n);
	line->len += n;
	line->str[line->len] = '\0';
	return (1);
}

/* Free's the state's buffer at end of file, or after an error. */
void	gnl_free(t_state *state)
{
	free(state->buffer);
	state->buffer = NULL;
	state->start = 0;
	state->len = 0;
}
