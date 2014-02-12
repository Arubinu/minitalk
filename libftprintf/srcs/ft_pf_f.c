/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:47:01 by apergens          #+#    #+#             */
/*   Updated: 2013/12/19 10:35:32 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pf_f(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return ("");
	str = ft_ftoa(va_arg(ap, double));
	*ret = ft_strlen(str);
	return (str);
}
