/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by apergens          #+#    #+#             */
/*   Updated: 2013/11/27 16:07:40 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writing a number in the console
*/

void	ft_putnbr_fd(int n, int fd)
{
	int			state;
	char		temp;

	state = (n < 0) ? 1 : 0;
	temp = n % 10 * (state ? -1 : 1) + '0';
	n = n / 10 * (state ? -1 : 1);
	if (state)
		ft_putchar_fd('-', fd);
	if (n)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(temp, fd);
	return ;
}
