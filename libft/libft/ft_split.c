/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:12:47 by rkander           #+#    #+#             */
/*   Updated: 2023/12/05 21:12:47 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*ft_cpy(char const *str, char c)
{
	char	*copy;
	int		w_len;
	int		i;

	i = 0;
	w_len = 0;
	while (*str && *str != c)
	{
		str++;
		w_len++;
	}
	str -= w_len;
	copy = (char *)malloc((w_len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (i < w_len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	free(array);
}

static char	**allocate_and_initialize_array(const char *s, char c, int w_count)
{
	char	**array;
	int		i;

	array = (char **)malloc((w_count + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < w_count)
	{
		while (*s == c)
			s++;
		array[i] = ft_cpy(s, c);
		if (array[i] == NULL)
		{
			free_array(array);
			return (NULL);
		}
		i++;
		while (*s && *s != c)
			s++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		w_count;
	char	**array;

	if (!s)
		return (NULL);
	w_count = words_count(s, c);
	array = allocate_and_initialize_array(s, c, w_count);
	return (array);
}
