/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pat <pat@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:37:13 by pat               #+#    #+#             */
/*   Updated: 2021/12/14 20:29:20 by pat              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int ft_check_sign(char c, va_list *va_params)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*va_params, int), 1));
	if (c == 's')
		return (ft_putstr_fd(va_arg(*va_params, char *), 1));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(*va_params, int), 1, 0));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*va_params, unsigned int), 0));
	if (c == 'p')
		return (ft_putptr(va_arg(*va_params, void *)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(*va_params, int), "0123456789abcdef", 0));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(*va_params, int), "0123456789ABCDEF", 0));
	if (c == '%')
	{
		write(1, &c, 1);
		return (1);
	}
	else
		return(ft_putchar_fd(c, 1));
	return (0);
	
}

int ft_printf(const char *arg, ...)
{
	va_list va_params;
	int		i;
	int		byte_read;

	i = 0;
	byte_read = 0;
	va_start(va_params, arg);
	while (arg[i])
	{
		if (arg[i] != '%')
		{
			write(1, &arg[i], 1);
			byte_read++;
		}
		else if (arg[i + 1])
		{
			i++;
			
			byte_read += ft_check_sign(arg[i], &va_params);
		}
		i++;
	}
	va_end(va_params);
	return (byte_read);
}


// int main()
// {
// 	char  c;

// 	c = 'c';
// 	printf("\n%i\n", ft_printf(" %u ", -1));
// 	printf("\n%i\n", printf(" %u ", -1));
// 	// ft_printf("%i %c t\n", -1, 'c');
// 	// printf("\n%i\n", ft_printf("%c %d %c=", 'f', 7, 'a'));
//  	// printf("\n%i\n", printf("%c %i", c, 15));
// 	return (0);
// }