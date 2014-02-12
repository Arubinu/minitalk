/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:48:05 by apergens          #+#    #+#             */
/*   Updated: 2013/12/19 01:48:16 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pf_d(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return ("");
	str = ft_itoa(va_arg(ap, int));
	*ret = ft_strlen(str);
	return (str);
}
