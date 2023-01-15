/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 18:09:30 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_server_pid;

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

static void	action(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (info->si_pid == g_server_pid)
	{
		ft_printf("successfully received by server\n", 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	char				*str;
	struct sigaction	s_sigaction;

	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sigaction, 0) < 0)
		return (ft_printf("Error\nsignal fail"), 1);
	if (argc != 3)
		return (ft_printf("Error\ninvalid number of args\n"));
	g_server_pid = ft_atoi(argv[1]);
	str = argv[2];
	if (str[0] == '\0')
		return (1);
	if (send_msg(g_server_pid, 0, 0, str) == 1)
		return (1);
	if (end_msg(g_server_pid) == 1)
		return (1);
	pause();
	return (0);
}
