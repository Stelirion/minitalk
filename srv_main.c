/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:52 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 18:10:36 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*fill_str(char *str, char *new)
{
	char		chr[2];

	if (!str)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
	}
	chr[0] = (char)ft_bin_to_int(new, 8);
	chr[1] = '\0';
	str = ft_strjoin_free(str, chr);
	return (str);
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static char	new[8];
	static int	byte;
	static char	*str;

	(void)context;
	if (sig == 31)
		new[byte] = '0';
	else if (sig == 30)
		new[byte] = '1';
	if (++byte == 8)
	{
		if (ft_strncmp(new, "00000000", 8) == 0)
		{
			ft_printf("%s", str);
			free(str);
			str = NULL;
			byte = 0;
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		str = fill_str(str, new);
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;
	pid_t				server_pid;

	server_pid = getpid();
	ft_printf("PID : %i\n", server_pid);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sigaction, 0) < 0)
		return (ft_printf("Error\nsignal fail"));
	if (sigaction(SIGUSR2, &s_sigaction, 0) < 0)
		return (ft_printf("Error\nsignal fail"));
	while (1)
		pause();
	return (0);
}
