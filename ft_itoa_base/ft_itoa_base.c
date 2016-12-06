/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 09:03:29 by exam              #+#    #+#             */
/*   Updated: 2016/12/06 09:21:26 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_power(int value, int base)
{
    int count;
    
    count = 0;
    while (base <= value)
    {
        ++count;
        value = value / base;
    }
    return (count);
}

int     ft_exp(int base, int power)
{
    return ((power == 0)? 1: base * ft_exp(base, --power));
}

char    convert(int value)
{
    return ((value >= 0 && value <= 9)? value + '0' : value - 10 + 'A');
}

char	*ft_itoa_base(int value, int base)
{
	int		neg;
	int		i;
    int     power;
    int     size;
	char	*str;

	neg = 0;
	i = 0;
    if (base < 2 || base > 16)
    {
        str = "";
        return (str);
    }
	if (value == -2147483648)
	{
		str = "-2147483648";
		return (str);
	}
	if (value == 2147483647)
	{
		str = "2147483647";
		return (str);
	}
	if (base == 10 && value < 0)
		neg = 1;
	if (value < 0)
		value = -value;
	power = get_power(value, base);
	size = power + 1 + neg;
	str = (char *)malloc(size);
	str[size] = '\0';
	if (neg == 1)
		str[i++] = '-';
	while (i < size)
	{
        str[i] = convert(value / ft_exp(base, power));
        value = value % ft_exp(base, power);
        --power;
        ++i;
	}
	return (str);
}