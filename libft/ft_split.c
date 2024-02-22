/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouabra < abouabra@student.1337.ma >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:38:10 by abouabra          #+#    #+#             */
/*   Updated: 2022/12/24 18:12:54 by abouabra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**error(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

static int	c_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*get_word(char *s, char c, int *index)
{
	int		i;
	int		wdlen;
	char	*str;

	wdlen = 0;
	i = 0;
	while (s[(*index)] == c)
		(*index)++;
	i = *index;
	while (s[i] && s[i] != c)
	{
		wdlen++;
		i++;
	}
	str = malloc((wdlen + 1) * (sizeof(char)));
	if (!str)
		return (0);
	i = 0;
	while (s[(*index)] && s[(*index)] != c)
		str[i++] = s[(*index)++];
	str[i] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		c_occurence;
	int		i;
	char	**arr;
	int		index;

	if (s == NULL)
		return (0);
	index = 0;
	i = 0;
	c_occurence = c_count(s, c);
	arr = malloc(sizeof(char *) * (c_occurence + 1));
	if (!arr)
		return (0);
	while (i < c_occurence)
	{
		arr[i] = get_word(s, c, &index);
		if (!arr)
			return (error(arr));
		i++;
	}
	arr[i] = 0;
	return (arr);
}
