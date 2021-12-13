/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmattheo <rmattheo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:46:39 by rmattheo          #+#    #+#             */
/*   Updated: 2021/11/17 19:14:00 by rmattheo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	i;

	if (!s && len > 0)
		return (NULL);
	i = ft_strlen(&s[start]);
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	d = malloc((char)len + 1);
	if (!d)
		return (NULL);
	d[len] = 0;
	d = ft_memcpy(d, &s[start], len);
	return (d);
}
