/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:30 by mkejji            #+#    #+#             */
/*   Updated: 2016/09/28 19:43:09 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "filler.h"

int	main(void)
{
	char	buf[1024];
	int		rd;
	int fd = open("logfile1", O_CREAT | O_RDWR);
	while((rd = read(1, buf, 1024)) > 0)
		write(fd, buf, rd);
	close(fd);
	return (1);
}
