/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnoronha <pnoronha@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 02:38:11 by pnoronha          #+#    #+#             */
/*   Updated: 2021/07/08 16:35:50 by pnoronha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	ft_printf(const char *string, ...)
{
	va_list	args;
	va_start(args, string);


	va_end(args);
	return (0);
}
