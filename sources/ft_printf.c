/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 02:38:11 by pnoronha          #+#    #+#             */
/*   Updated: 2021/08/11 20:04:25 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	t_tab	tab;
	char	*string_save;

	va_start(args, string);
	string_save = ft_strdup(string);
	init_struct(&tab, string_save, &args);
	passThrough_string(&tab);
	va_end(args);
	free(string_save);
	return (tab.length);
}

void	init_struct(t_tab *tab, char *string, va_list *args)
{
	tab->args = args;
	tab->imput = string;
	tab->length = 0;
	tab->index = 0;
}
