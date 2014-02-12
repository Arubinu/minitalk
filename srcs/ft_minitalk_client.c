/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_client.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 18:51:10 by apergens          #+#    #+#             */
/*   Updated: 2014/02/10 10:10:21 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int		ft_error(int argc, char **argv);
static int		ft_signal_start(char **argv);

int				main(int argc, char **argv)
{
	int		pid;
	char	*send;

	*argv = ft_strrchr(*argv, '/') + 1;
	if (!ft_signal_init(*argv))
		return (0);
	if (ft_error(argc, argv) || !(pid = ft_signal_start(argv)))
		return (0);
	send = NULL;
	if (argc == 3)
		send = argv[2];
	ft_read(send, pid, argv);
	return (0);
}

static int		ft_error(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
	{
		ft_printf_fd("Usage : %s <pid> <message>", STDERR_FILENO, *argv);
		return (1);
	}
	return (0);
}

static int		ft_signal_start(char **argv)
{
	int		err;
	int		pid;
	char	*tmp;

	err = ((pid = ft_atoi(*(argv + 1))) <= 0) ? 1 : 0;
	tmp = ft_itoa(pid);
	err = ft_strcmp(tmp, *(argv + 1)) ? 1 : err;
	free(tmp);
	if (err)
	{
		ft_printf_fd("%s: entry \"ID Server\" '", STDERR_FILENO, *argv);
		ft_printf_fd("%s` wrong.\n", STDERR_FILENO, *(argv + 1));
		return (0);
	}
	ft_signal_only(pid);
	return (pid);
}

void			ft_signal_user(int sig, char *client)
{
	*(client + ft_strlen(client) - 1) = '\0';
	if (DEBUG)
	{
		if (sig == SIGUSR1)
			ft_printf_fd("Signal [%s] : SIGUSR1\n", STDERR_FILENO, client);
		else if (sig == SIGUSR2)
			ft_printf_fd("Signal [%s] : SIGUSR2\n", STDERR_FILENO, client);
		else
			ft_printf_fd("Signal [%s] : %s\n", STDERR_FILENO, client, sig);
	}
	ft_signal_sleep(sig);
	return ;
}
