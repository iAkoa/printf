/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:40:47 by pat               #+#    #+#             */
/*   Updated: 2021/12/13 19:46:19 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

int ft_strcmp(char *str)
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

int    indx(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int    check(char *base)
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

int	ft_putnbr_base(int nbr, char *base, int i)
{
	long int	n;
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
		if (n >= idx)
			i = ft_putnbr_base(n / idx, base, i);
		i += ft_putchar_fd(base[n % idx], 1);
	}
	return (i);
}