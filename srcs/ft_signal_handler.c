/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 15:03:52 by apergens          #+#    #+#             */
/*   Updated: 2014/02/12 02:43:43 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	int		pid;
	char	*client;

	(void)context;
	pid = ft_signal_only(-1);
	if (!siginfo->si_pid) /* && !pid   ->   Prise en charge du PID 0 */
		return ;
	if (pid > 0 && siginfo->si_pid != pid)
		return ;
	if (DEBUG && pid)
		ft_printf_fd("pid : %d - %d\n", STDERR_FILENO, pid, siginfo->si_pid);
	if (siginfo->si_code == SIGINT || siginfo->si_code == SIGQUIT)
		ft_signal_exit(1);
	client = ft_itoa(siginfo->si_pid);
	client = ft_strfjoin1(&client, "=", 1);
	ft_signal_user(sig, client);
	free(client);
	return ;
}
