/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:56:02 by apergens          #+#    #+#             */
/*   Updated: 2014/02/10 10:07:53 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_write(int c, int pid, char *bin)
{
	int		i;
	char	*b2;

	i = -1;
	b2 = ft_ctob2(c);
	while (*(b2 + (++i)) != '\0')
	{
		usleep(WAIT_SEND);
		if (i && ft_signal_sleep(-1) != *(b2 + i - 1))
		{
			ft_printf_fd("%s: error when sending\n", STDERR_FILENO, bin);
			exit(-1);
		}
		kill(pid, *(b2 + i));
	}
	return ;
}
