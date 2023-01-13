/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:52 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/13 17:08:37 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bin_to_int(char *bin)
{
	int	n;

	n = 0;
	if (bin[0] == '1')
		n += 128;
	if (bin[1] == '1')
		n += 64;
	if (bin[2] == '1')
		n += 32;
	if (bin[3] == '1')
		n += 16;
	if (bin[4] == '1')
		n += 8;
	if (bin[5] == '1')
		n += 4;
	if (bin[6] == '1')
		n += 2;
	if (bin[7] == '1')
		n += 1;
	ft_printf("%c", n);
	return ;
}

static void	action(int sig, siginfo_t *info, void *context)
{
	static char	new[8];
	static int	byte;

	(void)info;
	(void)context;
	if (!byte)
		byte = 0;
	if (sig == 31)
		new[byte] = '0';
	if (sig == 30)
		new[byte] = '1';
	byte ++;
	if (byte == 8)
	{
		bin_to_int(new);
		byte = 0;
	}
}

int	main(void)
{
	struct sigaction	s_sigaction;
	pid_t				pid;

	pid = getpid();
	ft_printf("PID : %i\n", pid);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
