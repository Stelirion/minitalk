/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:52 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 12:29:51 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig, siginfo_t *info, void *context)
{
	static char		new[8];
	static char		len_bin[64];
	char			chr[2];
	static size_t	receve;
	static int		byte;
	static int		size;
	static char		*str;

	(void)info;
	(void)context;
	if (!byte)
		byte = 0;
	if (!size)
		size = 0;
	if (sig == 31 && size < 64)
		len_bin[size] = '0';
	else if (sig == 30 && size < 64)
		len_bin[size] = '1';
	else if (sig == 31 && size >= 64)
		new[byte] = '0';
	else if (sig == 30 && size >= 64)
		new[byte] = '1';
	if (size < 64)
		size++;
	else
		byte++;
	if (byte == 8)
	{
		if (!str)
		{
			str = malloc(sizeof(char));
			str[0] = '\0';
		}
		if (!receve)
			receve = 0;
		chr[0] = (char)ft_bin_to_int(new, 8);
		chr[1] = '\0';
		str = ft_strjoin_free(str, chr);
		byte = 0;
		receve++;
		if (receve == ft_bin_to_int(len_bin, 64))
		{
			ft_printf("%s\n", str);
			if (ft_strncmp(str, "quit", 10) == 0)
				exit(0);
			free(str);
			str = NULL;
			size = 0;
			receve = 0;
		}
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
