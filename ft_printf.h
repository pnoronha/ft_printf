/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:25:53 by pnoronha          #+#    #+#             */
/*   Updated: 2021/08/11 19:55:11 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_tab
{
	int			index;
	int			length;
	char		*imput;
	va_list		*args;
}				t_tab;

int	ft_printf(const char *string, ...);
void	passThrough_string(t_tab *tab);
void	conversion_select(t_tab *tab);
void	conversion_character(t_tab *tab);
void	conversion_string(t_tab *tab);
void	conversion_decimal(t_tab *tab);
void	conversion_pointer(t_tab *tab);
void	conversion_unsigned(t_tab *tab);
void	conversion_hexaDecimal(t_tab *tab);
void	init_struct(t_tab *tab, char *string, va_list *args);

#endif
