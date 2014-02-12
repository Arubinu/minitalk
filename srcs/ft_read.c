/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 15:53:41 by rkorimba          #+#    #+#             */
/*   Updated: 2014/02/10 09:55:51 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_read(char *send, int pid, char **argv)
{
	int		i;

	i = 0;
	if (send)
	{
		ft_send(send, pid, argv);
		return ;
	}
	while (get_next_line(STDIN_FILENO, &send) > 0)
	{
		ft_send(send, pid, argv);
		usleep(WAIT_PONG);
	}
	free(send);
	return ;
}
