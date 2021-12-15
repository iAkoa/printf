/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:53:07 by pat               #+#    #+#             */
/*   Updated: 2021/12/14 20:15:31 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_putptr(void *ptr)
{
	int iptr;
	unsigned long long	a;
	a = (unsigned long long)ptr;
	iptr = ft_putstr_fd("0x", 1);
	iptr += ft_putnbr_base_unsigned(a, "0123456789abcdef", 0);
	return (iptr);
}

// int main(void)
// {
// 	printf ("%p\n", -2);
// 	ft_printf("%p\n", -2);
// }