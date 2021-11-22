/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_treat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 22:23:07 by pnoronha          #+#    #+#             */
/*   Updated: 2021/11/22 18:34:30 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	conversion_character(t_tab *tab)
{
	char	character;

	character = va_arg(*tab->args, int);
	tab->length += write(1, &character, 1);
}

void	conversion_string(t_tab *tab)
{
	char	*str;

	str = va_arg(*tab->args, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		tab->length += ft_strlen("(null)");
		return ;
	}
	ft_putstr(str);
	tab->length += ft_strlen(str);
}

void	conversion_decimal(t_tab *tab)
{
	char	*str;
	int		decimal;

	decimal = va_arg(*tab->args, int);
	str = ft_itoa(decimal);
	ft_putstr(str);
	tab->length += ft_strlen(str);
	free(str);
}
