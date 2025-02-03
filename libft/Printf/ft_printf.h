/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:20:47 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 14:33:47 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define SP_CHAR 'c'
# define SP_STRING 's'
# define SP_DECIMAL 'd'
# define SP_INTEGER 'i'
# define SP_UNSIGN 'u'
# define SP_HEX_LOW 'x'
# define SP_HEX_UPP 'X'
# define SP_POINTER 'p'
# define SP_PERCENT '%'

# define VALID_SPECIFIERS "cspdiuxX%"

# define BASE_DECIMAL "0123456789"
# define BASE_HEX_LOWER "0123456789abcdef"
# define BASE_HEX_UPPER "0123456789ABCDEF"

char	*ft_itoa_base(int n, const char *base);

char	*ft_ltoa_base(long n, const char *base);

char	*ft_uitoa_base(unsigned long n, const char *base);

int		ft_printf(const char *format, ...);

int		ft_handle_pointer_specifier(va_list args);

int		ft_handle_str_specifier(va_list args);

int		ft_check_valid_spec(const char *format);

#endif