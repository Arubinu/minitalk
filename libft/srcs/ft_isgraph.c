/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isgraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 22:51:52 by apergens          #+#    #+#             */
/*   Updated: 2013/11/20 23:04:08 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isgraph(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
