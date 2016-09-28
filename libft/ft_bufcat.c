/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:49:07 by mkejji            #+#    #+#             */
/*   Updated: 2016/08/22 08:46:34 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buf	*ft_bufcat(t_buf *a, t_buf *b)
{
	t_buf	*new;

	new = ft_bufdup(a->buf);
	ft_bufappend(new, b->buf);
	return (new);
}
