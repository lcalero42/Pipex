/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer_specifier.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:48:41 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 14:32:48 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"

int	ft_handle_pointer_specifier(va_list args)
{
	long	arg;
	char	*str;
	size_t	len;

	arg = (long)va_arg(args, void *);
	if (arg == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	str = ft_uitoa_base(arg, BASE_HEX_LOWER);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len + 2);
}
