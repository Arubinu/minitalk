/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:36:09 by apergens          #+#    #+#             */
/*   Updated: 2014/02/10 09:24:09 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_tail(int client, int del)
{
	int			i;
	int			ret;
	static int	*stock;

	stock = (stock == NULL) ? (int *)malloc(sizeof(int) * NB_CLIENT) : stock;
	if (del)
	{
		i = 1;
		ret = *stock;
		*stock = 0;
		while (*(stock + i) && i < NB_CLIENT)
			*(stock + i - 1) = *(stock + i);
		*(stock + NB_CLIENT - 1) = 0;
		return (ret);
	}
	i = 0;
	if (client)
	{
		while (*(stock + i) && i < NB_CLIENT)
		{
			if (DEBUG)
				ft_printf("Stack [%d] %d\n", i, *(stock + i));
			i++;
		}
		if (i >= NB_CLIENT)
			return (*stock);
		*(stock + i) = client;
	}
	return (*(stock + i));
}
