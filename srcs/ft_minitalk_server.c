/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_server.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 18:23:02 by apergens          #+#    #+#             */
/*   Updated: 2014/02/12 02:54:16 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int				main(int argc, char **argv)
{
	(void)argc;
	*argv = ft_strrchr(*argv, '/') + 1;
	ft_printf("Serveur Started [pid:%d]\n", getpid());
	if (!ft_signal_init(*argv))
		return (0);
	signal(SIGINT, &ft_signal_exit);
	signal(SIGQUIT, &ft_signal_exit);
	while (!ft_exit(0))
		pause();
	ft_putendl("\nServeur Shutdown");
	return (0);
}

void			ft_signal_user(int sig, char *client)
{
	int				current;
	char			*tmp;
	char			**str;
	static t_client	lst;

	if ((current = ft_check_client(&lst, client)) != lst.client)
		return ;
	lst.client = current;
	str = (char **)(&ft_lstcmp(lst.lst, client)->content);
	lst.octet <<= 1;
	lst.octet += (sig == SIGUSR1) ? 1 : 0;
	if (ft_putsignal(&lst, str, &tmp, &current))
		kill(current, sig);
	return ;
}
