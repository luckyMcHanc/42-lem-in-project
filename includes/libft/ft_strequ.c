/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmhlanga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 13:29:41 by lmhlanga          #+#    #+#             */
/*   Updated: 2019/06/24 10:56:30 by lmhlanga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i])
		{
			if (s1[i] == s2[i])
			{
				i++;
			}
			else
			{
				return (0);
			}
		}
		if (s1[i] == '\0' && s2[i] != '\0')
			return (0);
		return (1);
	}
	return (0);
}
