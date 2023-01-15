/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 15:38:51 by ngennaro         ###   ########lyon.fr   */
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
					return (ft_printf("Error\nSignal fail"), 1);
			}
			else if (bin[j] == '1')
			{
				if (kill(pid, SIGUSR1) != 0)
					return (ft_printf("Error\nSignal fail"), 1);
			}
			temp();
			j++;
		}
		free(bin);
		i++;
	}
	return (0);
}

int	end_msg(int pid)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		if (kill(pid, SIGUSR2) != 0)
			return (ft_printf("Error\nSignal fail"), 1);
		temp();
		i--;
	}
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
	if (str[0] == '\0')
		return (1);
	if (send_msg(pid, 0, 0, str) == 1)
		return (1);
	if (end_msg(pid) == 1)
		return (1);
}
