/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/13 18:17:14 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*int_to_bin(char chr)
{
	int		len;
	char	*bin;

	len = 7;
	bin = malloc((len) * sizeof (char));
	while (len >= 0)
	{
		bin[len] = chr % 2 + '0';
		chr = chr / 2;
		len--;
	}
	bin = ft_strjoin_free(bin, "\0");
	return (bin);
}

int	send(int pid, int j, size_t i, char *str)
{
	char	*bin;

	while (str[i])
	{
		bin = int_to_bin(str[i]);
		j = 0;
		while (bin[j])
		{
			if (bin[j] == '0')
			{
				if (kill(pid, SIGUSR2) != 0)
					return (ft_printf("Error\nSignal error"));
			}
			else if (bin[j] == '1')
			{
				if (kill(pid, SIGUSR1) != 0)
					return (ft_printf("Error\nSignal error"));
			}
			usleep(100);
			j++;
		}
		free(bin);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		j;
	size_t	i;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error\ninvalid number of args\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	j = 0;
	send(pid, j, i, str);
}
