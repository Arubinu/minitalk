/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:54:27 by apergens          #+#    #+#             */
/*   Updated: 2014/02/07 20:57:01 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_signal_sleep(int sig)
{
	int			ret;
	static int	state;

	ret = state;
	if (sig >= 0)
		state = sig;
	return (ret);
}
