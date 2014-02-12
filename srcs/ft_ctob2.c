/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctob2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 00:28:36 by apergens          #+#    #+#             */
/*   Updated: 2014/02/08 16:31:14 by rkorimba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_ctob2(int c)
{
	int		nbr;
	char	*ret;

	nbr = -1;
	ret = ft_strnew(8);
	while (++nbr < 8)
	{
		*(ret + (7 - nbr)) = (c % 2) ? SIGUSR1 : SIGUSR2;
		c >>= 1;
	}
	return (ret);
}
