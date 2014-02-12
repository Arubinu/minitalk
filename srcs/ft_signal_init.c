/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:55:24 by apergens          #+#    #+#             */
/*   Updated: 2014/02/09 22:37:13 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_signal_init(char *bin)
{
	int					err;
	struct sigaction	act;

	err = 0;
	act.sa_sigaction = &ft_signal_handler;
	act.sa_flags = SA_SIGINFO;
	if (!err && sigaction(SIGUSR1, &act, NULL) < 0 && (err = 1))
		ft_printf_fd("%s: error to start sigaction\n", STDERR_FILENO, bin);
	if (!err && sigaction(SIGUSR2, &act, NULL) < 0 && (err = 1))
		ft_printf_fd("%s: error to start sigaction\n", STDERR_FILENO, bin);
	if (err)
		return (0);
	return (1);
}
