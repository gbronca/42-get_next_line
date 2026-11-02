/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:20:41 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/11/02 15:34:31 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
Fetches the next line from the state's buffer into the line structure.
Returns 1 if a new line was found, 0 if more data is needed, -1 on error.
*/
static int	gnl_fetch_line(t_state *state, t_line *line)
{
	size_t	end;
	int		new_line;

	if (!state->buffer || state->start == state->len)
		return (0);
	end = state->start;
	while (end < state->len && state->buffer[end] != '\n')
		end++;
	new_line = (end < state->len);
	if (new_line)
		end++;
	if (!gnl_append(line, state->buffer + state->start, end - state->start))
		return (-1);
	state->start = end;
	return (new_line);
}

/*
Reads from the file descriptor into the state's buffer and fetches lines
into the line structure.
Returns 1 if a new line was found, 0 if more data is needed, -1 on error.
*/
static int	read_line(int fd, t_state *state, t_line *line)
{
	int	status;

	status = gnl_fetch_line(state, line);
	while (status == 0)
	{
		status = gnl_read_fd(fd, state);
		if (status <= 0)
			return (status);
		status = gnl_fetch_line(state, line);
	}
	return (status);
}

/*
Fetches the next line from the file descriptor.
Returns the line as a string, or NULL on error or end of file.
*/
char	*get_next_line(int fd)
{
	static t_state	state[GNL_FD_MAX];
	t_line			line;
	int				status;

	if (fd < 0 || fd >= GNL_FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line.str = NULL;
	line.len = 0;
	line.capacity = 0;
	status = read_line(fd, &state[fd], &line);
	if (status <= 0)
		gnl_free(&state[fd]);
	if (status < 0 || line.len == 0)
	{
		free(line.str);
		return (NULL);
	}
	return (line.str);
}
