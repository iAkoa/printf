/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 02:57:15 by pat               #+#    #+#             */
/*   Updated: 2021/12/13 19:17:26 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, int i)
{	
	if (fd == 0)
		return (-1);
	else if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	else if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		i = ft_putnbr_fd(n / 10, fd, i);
	i += ft_putchar_fd(n % 10 + '0', fd);
	
	return (i);
}