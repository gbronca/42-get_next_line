/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 17:20:41 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/10/29 16:57:51 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char	*get_next_line(int fd)
// {

// }

// Remove before submitting

#include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	buffer[1024];
	int		chars_read;

	fd = open("README.md", O_RDONLY);
	while ((chars_read = read(fd, buffer, 25)))
	{
		buffer[chars_read] = '\0';
		printf("from md -> %s\n", buffer);
	}
	
	return (0);
}