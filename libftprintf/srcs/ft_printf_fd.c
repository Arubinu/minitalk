/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apergens <apergens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by apergens          #+#    #+#             */
/*   Updated: 2013/12/25 21:10:01 by apergens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_fd(const char *format, int fd, ...)
{
	va_list		ap;
	char		*ptr;
	char		*str;
	size_t		len;

	len = 0;
	ptr = (char *)format;
	va_start(ap, fd);
	while (*ptr && (len += ft_get_v_arg(ap, &ptr, &str, fd)))
		;
	va_end(ap);
	return ((int)len);
}
