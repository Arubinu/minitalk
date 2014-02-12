/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_client.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 18:54:03 by apergens          #+#    #+#             */
/*   Updated: 2014/02/12 02:43:49 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_check_client(t_client *lst, char *client)
{
	int		pid;

	pid = ft_atoi(client);
	if (lst->client && lst->client != pid) /* && pid   ->   Prise en charge du PID 0 */
	{
		ft_tail(pid, 0);
		usleep(WAIT_PONG);
		kill(pid, SIGUSR2);
	}
	else if (!lst->client)
	{
		lst->client = pid;
		usleep(WAIT_PONG);
		kill(pid, SIGUSR1);
		pid = 0;
	}
	else
		return (pid);
	if (lst->lst == NULL)
		lst->lst = ft_lstnew(client, ft_strlen(client));
	if (ft_lstcmp(lst->lst, client) == NULL)
		ft_lstadd(&lst->lst, ft_lstnew(client, ft_strlen(client)));
	return (pid);
}
