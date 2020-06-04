/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdublicate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 15:51:53 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/07/21 17:54:19 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strexist(char **s, char *c, int i)
{
	int x;

	x = 0;
	while (x < i && s[x])
	{
		if (ft_strcmp(s[x], c) == 0)
			return (1);
		x++;
	}
	return (0);
}

int		isdublicate(char **s)
{
	int i;

	i = 1;
	while (s[i])
	{
		if (ft_strexist(s, s[i], i))
			return (0);
		i++;
	}
	return (1);
}
