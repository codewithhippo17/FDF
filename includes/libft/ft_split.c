/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:30:27 by ehamza            #+#    #+#             */
/*   Updated: 2024/11/02 15:12:57 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlenc(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_split(const char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_freemem(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = (char **)malloc ((count_split(s, c) + 1) * 8);
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			split[i] = malloc(ft_strlenc(s, c) + 1);
			if (!split[i])
				return (ft_freemem(split, i));
			j = 0;
			while (*s != c && *s)
				split[i][j++] = *s++;
			split[i++][j] = 0;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>

// int	main()
// {
// 	int i;
// 	char	str[] = ",,,,,,,,sasa,,,,,,with,hipoh,gggghgssshggghhg,,,,,,,";
// 	char	**res = ft_split(str, ',');

// 	if (!res)
// 	{
// 		write(1, "Error: ft_split failed\n", 24);
// 		return (1);
// 	}
// 	i = 0;
// 	while (res[i])
// 	{
// 		printf( "%s\n", res[i]);
// 		i++;
// 	}
// 	printf("%s \n", res[i]);
// 	ft_freemem(res, i);
// 	free(res);
// 	return (0);
// }
