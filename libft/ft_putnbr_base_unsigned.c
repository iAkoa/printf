/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:55:09 by pat               #+#    #+#             */
/*   Updated: 2021/12/14 20:40:42 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_strcmp(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int    indx(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int    check(char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (indx(base) < 2)
		return (0);
	if (ft_strcmp(base))
		return (0);
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

int	ft_putnbr_base_unsigned(unsigned long long nbr, char *base, int i)
{
	unsigned long long	n;
	int			idx;

	idx = indx(base);
	n = nbr;
	if (check(base))
	{
		if (n < 0)
		{
			n = -n;
			write(1, "-", 1);
			i++;
		}
		if (n >= (unsigned int)idx)
			i = ft_putnbr_base_unsigned(n / idx, base, i);
		i += ft_putchar_fd(base[n % idx], 1);
	}
	return (i);
}