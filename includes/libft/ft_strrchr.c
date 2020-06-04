/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:07:23 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/07/21 15:55:15 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_pos;

	last_pos = (0);
	if (s)
	{
		while (*s)
		{
			if (*s == c)
				last_pos = (char*)s;
			++s;
		}
		if (last_pos)
			return (last_pos);
		if (c == '\0')
			return ((char*)s);
		return (0);
	}
	return (NULL);
}
