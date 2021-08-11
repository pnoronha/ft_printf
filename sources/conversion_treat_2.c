/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_treat_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 02:48:13 by pnoronha          #+#    #+#             */
/*   Updated: 2021/08/11 19:53:22 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	conversion_pointer(t_tab *tab)
{
	unsigned long	ptr;

	ptr = va_arg(*tab->args, unsigned long);
	if (ptr == 0)
	{
		ft_putstr("(nil)");
		tab->length += ft_strlen("(nil)");
		return ;
	}
	tab->length += write(1, "0x", 2);
	tab->length += ft_putnbrBase((long int)ptr, "0123456789abcdef");
}

void	conversion_unsigned(t_tab *tab)
{
	unsigned long long	nbr_long;
	char				*str;

	nbr_long = va_arg(*tab->args, unsigned int);
	str = ft_utoa(nbr_long);
	ft_putstr(str);
	tab->length += ft_strlen(str);
	free(str);
}

void	conversion_hexaDecimal(t_tab *tab)
{
	long	hexa;

	hexa = va_arg(*tab->args, unsigned int);
	if (tab->imput[tab->index] == 'x')
		tab->length += ft_putnbrBase(hexa, "0123456789abcdef");
	else
		tab->length += ft_putnbrBase(hexa, "0123456789ABCDEF");
}
