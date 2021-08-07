/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_iteration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:48:15 by pnoronha          #+#    #+#             */
/*   Updated: 2021/08/07 11:37:48 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	passThrough_string(s_tab *tab)
{
	while (tab->imput[tab->index] != '\0')
	{
		if (tab->imput[tab->index] == (char)'%')
			conversion_select(tab);
		else
			tab->length += write(1, &tab->imput[tab->index], 1);
		tab->index++;
	}
}

void	conversion_select(s_tab *tab)
{
	tab->index++;
	if (tab->imput[tab->index] == (char)'c')
		conversion_character(tab);
	if (tab->imput[tab->index] == (char)'s')
		conversion_string(tab);
	if (tab->imput[tab->index] == (char)'d')
		conversion_decimal(tab);
	if (tab->imput[tab->index] == (char)'i')
		conversion_decimal(tab);
	if (tab->imput[tab->index] == (char)'p')
		conversion_pointer(tab);
	if (tab->imput[tab->index] == (char)'u')
		conversion_unsigned(tab);
	if (tab->imput[tab->index] == (char)'x')
		conversion_hexaDecimal(tab);
	if (tab->imput[tab->index] == (char)'X')
		conversion_hexaDecimal(tab);
	if (tab->imput[tab->index] == (char)'%')
		tab->length += write(1, &tab->imput[tab->index], 1);
}
