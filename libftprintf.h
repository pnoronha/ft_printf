/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:07:24 by pnoronha          #+#    #+#             */
/*   Updated: 2021/07/07 17:07:24 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct t_tab
{
	int			index;
	int			length;
	char		*imput;
	va_list		*args;
}				s_tab;

typedef struct	t_flags
{
	int			dot;
	int			star;
	int			minus;
	int			zero;
	int			width;
	int 		type;
	int			count;

}				s_flags;

int	ft_printf(const char *string, ...);
void	passThrough_string(s_tab *tab);
void	conversion_select(s_tab *tab);
void	conversion_character(s_tab *tab);
void	conversion_string(s_tab *tab);
void	conversion_decimal(s_tab *tab);
void	conversion_pointer(s_tab *tab);
void	conversion_unsigned(s_tab *tab);
void	conversion_hexaDecimal(s_tab *tab);
void	init_struct(s_tab *tab, char *string, va_list *args);
s_flags	init_flags(void);

#endif
