/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 00:35:22 by mkejji            #+#    #+#             */
/*   Updated: 2016/08/07 00:36:08 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCT_H
# define FT_STRUCT_H
# include <string.h>
# include <stdarg.h>

typedef struct				s_buf
{
	char	*buf;
	size_t	size;
	size_t	cap;
}							t_buf;

typedef unsigned char		t_uchar;
typedef unsigned int		t_uint;
typedef unsigned long long	t_ulong;
typedef void				(*t_conv)(va_list*, t_buf*);

typedef struct				s_func
{
	t_uchar			key;
	t_conv			func;
	struct s_func	*left;
	struct s_func	*right;
}							t_func;

typedef	struct				s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}							t_list;

#endif
