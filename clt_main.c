/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/11 14:30:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*int_to_bin(int chr)
{
	int		tmp;
	int		len;
	char	*bin;

	tmp = chr;
	len = 0;
	while (tmp)
	{
		tmp = tmp / 2;
		len++;
	}
	bin = malloc((len) * sizeof (char));
	while (len >= 0)
	{
		bin[len] = chr % 2 + '0';
		chr = chr / 2;
		len--;
	}
	return (bin);
}

int	main(int argc, char **argv)
{
	int		pid;
	size_t	i;
	char	*bin;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error\ninvalid number of args\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		bin = int_to_bin(str[i]);
		ft_printf(" %s", bin);
		i++;
	}
}
