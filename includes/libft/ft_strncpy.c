/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 14:23:40 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/07/04 12:11:57 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest && src)
	{
		while (src[i] != '\0' && i < n)
		{
			dest[i] = src[i];
			++i;
		}
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
		return (dest);
	}
	return (NULL);
}
