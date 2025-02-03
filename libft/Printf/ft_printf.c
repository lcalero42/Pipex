/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:30:41 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 14:32:30 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

static void	convert_print_num(int *len, const char *base, va_list args, char sp)
{
	char	*s;

	s = NULL;
	if (sp == SP_HEX_LOW || sp == SP_HEX_UPP)
		s = ft_ltoa_base((long)va_arg(args, unsigned int), base);
	else if (sp == SP_UNSIGN)
		s = ft_uitoa_base((unsigned long)va_arg(args, unsigned), base);
	else if (sp == SP_DECIMAL || sp == SP_INTEGER)
		s = ft_itoa_base((long)va_arg(args, int), base);
	else
		return ;
	if (!s)
		return ;
	ft_putstr_fd(s, 1);
	*len = ft_strlen(s);
	free(s);
}

static int	check_specifier(const char *s, int i, va_list args)
{
	int		len;

	if (s[i] != '%' || !s[i + 1])
		return (0);
	if (s[i + 1] == SP_CHAR)
		return (ft_putchar_fd((char)va_arg(args, int), 1), 1);
	else if (s[i + 1] == SP_PERCENT)
		return (ft_putchar_fd('%', 1), 1);
	else if (s[i + 1] == SP_STRING)
		return (ft_handle_str_specifier(args));
	else if (s[i + 1] == SP_DECIMAL || s[i + 1] == SP_INTEGER)
		return (convert_print_num(&len, BASE_DECIMAL, args, SP_DECIMAL), len);
	else if (s[i + 1] == SP_POINTER)
		return (ft_handle_pointer_specifier(args));
	else if (s[i + 1] == SP_UNSIGN)
		return (convert_print_num(&len, BASE_DECIMAL, args, SP_UNSIGN), len);
	else if (s[i + 1] == SP_HEX_LOW)
		return (convert_print_num(&len, BASE_HEX_LOWER, args, SP_HEX_LOW), len);
	else if (s[i + 1] == SP_HEX_UPP)
		return (convert_print_num(&len, BASE_HEX_UPPER, args, SP_HEX_UPP), len);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	int			res;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += check_specifier(format, i, args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			res++;
			i++;
		}
	}
	va_end(args);
	return (res);
}
