/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 11:53:07 by pat               #+#    #+#             */
/*   Updated: 2021/12/13 19:11:53 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long iptr;
	int			a;

	a = (unsigned long) ptr;
	iptr = ft_putstr_fd("0x", 1);
	iptr += ft_putnbr_base(a, "0123456789abcdef", 0);
	return (iptr);
}