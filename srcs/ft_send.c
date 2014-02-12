/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 16:25:43 by rkorimba          #+#    #+#             */
/*   Updated: 2014/02/10 10:08:33 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(char *send, int pid, char **argv)
{
	int		i;

	i = 0;
	kill(pid, SIGUSR1);
	if (DEBUG)
		ft_putendl("Attente de réponse du serveur !");
	sleep(WAIT_PING);
	if (ft_signal_sleep(-1) != SIGUSR1 && ft_signal_sleep(-1) != SIGUSR2)
	{
		ft_printf_fd("%s: server '%s` ", STDERR_FILENO, *argv, *(argv + 1));
		ft_putendl_fd("not responding.", STDERR_FILENO);
		exit(0);
	}
	if (DEBUG)
	{
		if (ft_signal_sleep(-1) == SIGUSR1)
			ft_putendl("Transmission en cours");
		else if (ft_signal_sleep(-1) == SIGUSR2)
			ft_putendl("Mis en attente");
	}
	while (ft_signal_sleep(-1) != SIGUSR1)
		pause();
	ft_signal_sleep(0);
	while (*(send + i) != '\0')
		ft_signal_write(*(send + (i++)), pid, *argv);
	ft_signal_write('\0', pid, *argv);
	if (DEBUG)
		ft_putendl("Fin de transmission");
	usleep(WAIT_PONG);
	return ;
}
