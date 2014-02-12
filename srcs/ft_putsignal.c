/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsignal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 22:08:48 by apergens          #+#    #+#             */
/*   Updated: 2014/02/12 02:55:42 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_putsignal(t_client *lst, char **str, char **tmp, int *current)
{
	int		ret;

	if (!(ret = 0) && ++lst->bit >= 8)
	{
		/* Décalage si trop de signaux   ->   A proscrire
		while (lst->bit-- > 8)
			lst->octet >>= 1;
		*/
		*tmp = ft_ctoa(lst->octet);
		lst->bit = 0;
		lst->octet = lst->octet >> 8;
		if (**tmp == '\0')
		{
			if (lst->client != lst->old)
				ft_printf("[%d] ", lst->client);
			ft_putendl(ft_strchr(*str, '=') + 1);
			*(*str + ft_strcchr(*str, '=') + 1) = '\0';
			if ((lst->old = lst->client) >= 0 && (lst->client = ft_tail(0, 1)))
				kill(lst->client, SIGUSR1);
			*current = lst->client;
		}
		else if (++ret)
			*str = ft_strfjoin1(str, *tmp, 1);
		free(*tmp);
		lst->octet = 0;
	}
	else
		++ret;
	return (ret);
}
