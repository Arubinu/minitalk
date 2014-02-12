/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_only.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 22:23:45 by apergens          #+#    #+#             */
/*   Updated: 2014/02/09 22:23:57 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_signal_only(int pid)
{
	static int	save;

	if (pid >= 0)
		save = pid;
	return (save);
}
