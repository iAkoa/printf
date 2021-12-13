/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:35:07 by pat               #+#    #+#             */
/*   Updated: 2021/12/13 19:40:03 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned_fd(unsigned int n, int fd, int i)
{	
	if (fd == 0)
		return (-1);
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