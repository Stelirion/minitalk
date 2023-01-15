/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 10:58:55 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	temp(void)
{
	int	i;

	i = 10;
	while (i-- > 0)
	{
		usleep(10);
	}
}

int	send_msg(int pid, int j, size_t i, char *str)
{
	char	*bin;

	while (str[i])
	{
		bin = ft_int_to_bin(str[i], 8);
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
			temp();
			j++;
		}
		free(bin);
		i++;
	}
	return (0);
}

int	send_len(int pid, int j, size_t len)
{
	char	*bin;

	bin = ft_int_to_bin(len, 64);
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
		temp();
		j++;
	}
	free(bin);
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error\ninvalid number of args\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	send_len(pid, 0, ft_strlen(str));
	send_msg(pid, 0, 0, str);
}
