/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:20:41 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/30 18:08:13 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		chars_read;
	char	*line;

	while ((chars_read = read(fd, buffer, 100)))
	{
		buffer[chars_read] = '\0';
		line = malloc(sizeof(char) * chars_read);
		if (!line)
			return (NULL);
		return (line);
	}
	return ("'a'");

}
