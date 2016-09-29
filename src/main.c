/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:30 by mkejji            #+#    #+#             */
/*   Updated: 2016/09/29 09:34:58 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "filler.h"

int	main(void)
{
	int		fd;
	int		n;
	char	buf[1024];

	fd = open("mkejji.trace", O_CREAT | O_WRONLY);
	while ((n = read(0, buf, 1024)))
		write(fd, buf, n);
	return (1);
}
