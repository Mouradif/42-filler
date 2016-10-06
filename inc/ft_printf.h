/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 04:06:35 by mkejji            #+#    #+#             */
/*   Updated: 2016/08/07 00:33:19 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif
# include "libft.h"
# include <stdarg.h>

int				ft_vdprintf(int fd, const char *format, va_list args);
int				ft_printf(const char *fmt, ...);
void			ft_die(char *fmt, ...);
t_func			*ft_func_new(t_uchar hash, t_conv func);
void			ft_func_add(t_func **head, t_func *node);
t_conv			ft_func(t_uchar key, t_func *head);
void			ft_conv_pc(va_list *args, t_buf *b);
void			ft_conv_d(va_list *args, t_buf *b);
void			ft_conv_c(va_list *args, t_buf *b);
void			ft_conv_i(va_list *args, t_buf *b);
void			ft_conv_ld(va_list *args, t_buf *b);
void			ft_conv_u(va_list *args, t_buf *b);
void			ft_conv_s(va_list *args, t_buf *b);
void			ft_conv_ls(va_list *args, t_buf *b);
void			ft_conv_o(va_list *args, t_buf *b);
void			ft_conv_x(va_list *args, t_buf *b);
void			ft_conv_ux(va_list *args, t_buf *b);
void			ft_conv_b(va_list *args, t_buf *b);
void			ft_make_buffer(t_buf **b, const char *fmt, va_list va);

#endif
