/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:19:10 by mkejji            #+#    #+#             */
/*   Updated: 2015/12/20 19:19:13 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	len = end - start + 1;
	if (len < 0)
		len = 0;
	if (!(ret = ft_strsub(s, start, len)))
		return (NULL);
	return (ret);
}
