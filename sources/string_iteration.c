/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_iteration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:48:15 by pnoronha          #+#    #+#             */
/*   Updated: 2021/11/22 18:34:27 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pass_through_string(t_tab *tab)
{
	while (tab->imput[tab->index] != '\0')
	{
		if (tab->imput[tab->index] == (char) '%')
			conversion_select(tab);
		else
			tab->length += write(1, &tab->imput[tab->index], 1);
		tab->index++;
	}
}

void	conversion_select(t_tab *tab)
{
	tab->index++;
	if (tab->imput[tab->index] == (char) 'c')
		conversion_character(tab);
	if (tab->imput[tab->index] == (char) 's')
		conversion_string(tab);
	if (tab->imput[tab->index] == (char) 'd')
		conversion_decimal(tab);
	if (tab->imput[tab->index] == (char) 'i')
		conversion_decimal(tab);
	if (tab->imput[tab->index] == (char) 'p')
		conversion_pointer(tab);
	if (tab->imput[tab->index] == (char) 'u')
		conversion_unsigned(tab);
	if (tab->imput[tab->index] == (char) 'x')
		conversion_hexadecimal(tab);
	if (tab->imput[tab->index] == (char) 'X')
		conversion_hexadecimal(tab);
	if (tab->imput[tab->index] == (char) '%')
		tab->length += write(1, &tab->imput[tab->index], 1);
}
