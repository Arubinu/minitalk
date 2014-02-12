/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:47:01 by apergens          #+#    #+#             */
/*   Updated: 2013/12/19 01:47:19 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_pf_s(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return ("");
	str = va_arg(ap, char *);
	*ret = ft_strlen(str);
	return (str);
}
