/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarbosa <nbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 09:42:57 by nbarbosa          #+#    #+#             */
/*   Updated: 2026/01/12 11:53:57 by nbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_words(char const *s, char c)
{
	int	count;
	int	i;
	int	in_word;

	in_word = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	ft_wordindex(const char *s, char c, int *start, int *end)
{
	while (s[*start] == c)
		(*start)++;
	*end = *start;
	while (s[*end] && s[*end] != c)
		(*end)++;
	return ;
}

static char	*ft_stdup(const char *s, char c, int *start, int *end)
{
	char	*strtocpy;
	int		x;

	x = 0;
	ft_wordindex(s, c, start, end);
	strtocpy = malloc(sizeof(char) * (*end - *start) + 1);
	if (!strtocpy)
		return (0);
	while (x < *end - *start)
	{
		strtocpy[x] = s[*start + x];
		x++;
	}
	strtocpy[x] = '\0';
	x = 0;
	return (strtocpy);
}

char	**ft_split(char const *s, char c)
{
	int		end;
	int		start;
	char	**res;
	int		index;
	int		count;

	index = 0;
	start = 0;
	end = 0;
	count = 0;
	count = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (count + 1));
	if (!res)
		return (0);
	while (index < count)
	{
		res[index] = ft_stdup(s, c, &start, &end);
		index++;
		start = end;
	}
	res[count] = NULL;
	return (res);
}

void	ft_free_split(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}
