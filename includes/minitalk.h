/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 20:52:33 by apergens          #+#    #+#             */
/*   Updated: 2014/02/12 02:54:07 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>

# include "libft.h"
# include "libftprintf.h"

# define DEBUG		0
# define NB_CLIENT	15
# define WAIT_PING	1
# define WAIT_PONG	1000
# define WAIT_SIG	1
# define WAIT_SEND	1000

typedef struct	s_client
{
	int		bit;
	int		client;
	int		old;
	char	octet;
	t_list	*lst;
}				t_client;

int		ft_check_client(t_client *lst, char *client);
char	*ft_ctob2(int c);
int		ft_exit(int quit);
int		ft_putsignal(t_client *lst, char **str, char **tmp, int *current);
void	ft_read(char *send, int pid, char **argv);
void	ft_send(char *send, int pid, char **argv);
void	ft_signal_exit(int sig);
void	ft_signal_handler(int sig, siginfo_t *siginfo, void *context);
int		ft_signal_init(char *bin);
int		ft_signal_only(int pid);
int		ft_signal_sleep(int sig);
void	ft_signal_user(int sig, char *client);
void	ft_signal_write(int c, int pid, char *bin);
int		ft_tail(int client, int del);

#endif
