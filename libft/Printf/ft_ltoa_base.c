/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:06:12 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 14:33:01 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_digits_base(long n, const char *base)
{
	long	num;
	int		cpt;

	cpt = 0;
	num = (long) n;
	if (num < 0)
	{
		cpt++;
		num *= -1;
	}
	while (num > 0)
	{
		num /= ft_strlen(base);
		cpt++;
	}
	if (n == 0)
		cpt = 1;
	return (cpt);
}

char	*ft_ltoa_base(long n, const char *base)
{
	char	*res;
	int		i;
	long	num;

	res = malloc(sizeof(char) * (count_digits_base(n, base) + 1));
	if (res == NULL)
		return (NULL);
	i = count_digits_base(n, base);
	num = (long) n;
	if (n < 0)
		num = -num;
	res[i--] = '\0';
	while (num > 0)
	{
		res[i] = base[num % ft_strlen(base)];
		num /= ft_strlen(base);
		i--;
	}
	if (n < 0)
		res[i] = '-';
	if (n == 0)
		res[i] = base[0];
	return (res);
}
