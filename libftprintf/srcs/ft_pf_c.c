/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:47:28 by apergens          #+#    #+#             */
/*   Updated: 2013/12/22 15:42:55 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pf_c(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return ("");
	str = (char *)malloc(sizeof(char) * 2);
	*str = (*opts == '%') ? '%' : va_arg(ap, int);
	*(str + 1) = '\0';
	*ret = 1;
	return (str);
}
