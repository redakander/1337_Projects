/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:51:19 by rkander           #+#    #+#             */
/*   Updated: 2023/12/16 17:57:15 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == 0 || f == 0)
		return (0);
	while (s[i])
		i++;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (p == 0)
		return (0);
	while (j < i)
	{
		p[j] = f(j, s[j]);
		j++;
	}
	p[j] = '\0';
	return (p);
}
