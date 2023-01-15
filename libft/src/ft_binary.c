/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:47:58 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 11:15:06 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_bin_to_int(char *str, int size)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		if (str[i] == 49)
			j = j + ft_pwr(size - i - 1, 2);
		i++;
	}
	if (str[i] == 49)
		j = j + 1;
	return (j);
}

char	*ft_int_to_bin(size_t number, size_t len)
{
	char	*bin;

	bin = malloc((len) * sizeof (char) + 1);
	bin[len] = '\0';
	while (len > 0)
	{
		len--;
		bin[len] = number % 2 + '0';
		number = number / 2;
	}
	return (bin);
}
