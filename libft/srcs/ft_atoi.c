/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 06:20:18 by apergens          #+#    #+#             */
/*   Updated: 2013/11/26 11:47:03 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	char	*trim;
	int		negative;

	result = 0;
	trim = ft_strtrim(str);
	if (trim == NULL || !*trim)
		return (0);
	negative = (*trim == '-') ? 1 : 0;
	trim += (*trim == '-' || *trim == '+') ? 1 : 0;
	while (*trim)
	{
		if (ft_isdigit(*trim))
			result = result * 10 + (*trim - '0');
		else
			break ;
		trim++;
	}
	result = negative ? result * -1 : result;
	return (result);
}
