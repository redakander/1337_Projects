/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 20:13:44 by rkander           #+#    #+#             */
/*   Updated: 2023/12/21 15:46:22 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst > src)
		while (len--)
			*(char *)(dst + len) = *(char *)(src + len);
	else if (dst < src)
		while (++i < len)
			*(char *)(dst + i) = *(char *)(src + i);
	return (dst);
}
