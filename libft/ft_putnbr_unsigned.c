/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:19:01 by pat               #+#    #+#             */
/*   Updated: 2021/12/14 20:30:33 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n, int i)
{	
	if (n >= 10)
		i = ft_putnbr_unsigned(n / 10, i);
	i += ft_putchar_fd(n % 10 + '0', 1);
	
	return (i);
}