/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abollen <abollen@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:01:38 by abollen           #+#    #+#             */
/*   Updated: 2022/02/08 15:08:54 by abollen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static char	*ft_gnlstrjoin(char *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		len;

	i = -1;
	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	dst = malloc(sizeof(char) * len + 2);
	if (!dst)
		return (NULL);
	if (s1 != NULL)
		while (s1[++i])
			dst[i] = s1[i];
	i = -1;
	while (s2[++i])
		dst[i + ft_strlen(s1)] = s2[i];
	dst[i + ft_strlen(s1)] = ' ';
	dst[i + ft_strlen(s1) + 1] = '\0';
	if (s1)
		free(s1);
	return (dst);
}

char	*arrayinit(int argc, char **argv)
{
	char	*array;
	char	*temp;
	int		i;

	i = 0;
	array = NULL;
	if (argc > 2)
	{
		while (argv[++i])
		{
			temp = array;
			array = ft_gnlstrjoin(array, argv[i]);
			if (!array)
			{
				free(temp);
				return (NULL);
			}	
		}
	}
	else
		array = ft_strdup(argv[1]);
	return (array);
}

void	checkint(char *array)
{
	int	i;

	i = -1;
	while (array[++i] && array[i + 1])
	{
		while (array[i] == ' ')
			i++;
		if (array[i] == '-' && ft_isdigit(array[i + 1]))
		{
			if (i == 0 || array[i - 1] == ' ')
				i++;
			else
				ft_error("Error\n");
		}
		if (array[i] && !(ft_isdigit(array[i])))
			ft_error("Error\n");
	}
}
