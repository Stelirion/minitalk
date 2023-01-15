/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:52 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 10:53:48 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*struct s_sig	sig_len (struct s_sig str, int sig)
{
	if (sig == 31)
		str.len[str.size] = '0';
	else
		str.len[str.size] = '1';
	str.chain = 1;
	return (str);

}

struct s_sig	sig_str(struct s_sig str, int sig)
{
	static size_t	i;
	static	size_t	byte;

	if (!byte)
		byte = 0;

	if (!i)
		i = 0;
	if (sig == 31)
		str.new[byte] = '0';
	else
		str.new[byte] = '1';
	byte++;
	if (byte == 8)
	{
		str.str[i] = (char)ft_bin_to_int(str.new, 8);
		byte = 0;
	}
	if (i == str.chain)
	{
		str.chain = 0;
		i = -1;
	}
	i++;
return(str);
}

void ft_signal(int sig)
{
	static struct s_sig	str;
	static int size;
	static size_t chain;

	if (!chain)
	{
		chain = 0;
		str.byte = 0;
	}
	if (!size)
		size = 0;
	if (size < 64)
	{
		sig_len (str, sig);
		size++;
		chain++;
		if (size == 64)
			chain = ft_bin_to_int(str.len, 8);
		return ;
	}
	if (!str.str)
	{
		str.str = malloc (sizeof(char) * size + 1);
		str.str[size] = '\0';
	}
	if (size != 0)
		sig_str(str, sig);
	if (chain == 0)
	{
		ft_printf ("%s\n", str.str);
		size = 0;
		str.byte = 0;
	}
}
static void	action(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	ft_signal(sig);
}*/


static void	action(int sig, siginfo_t *info, void *context)
{
	static char	new[8];
	static char	len_bin[64];
	static size_t	receve;
	static int	byte;
	static int	size;
	static char	*str;
	char		temp[2];

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
		temp[0] = (char)ft_bin_to_int(new, 8);
		temp[1] = '\0';
		str = ft_strjoin(str, temp);
		byte = 0;
		receve++;
		if (receve == ft_bin_to_int(len_bin, 64))
		{
			str = ft_strjoin(str, "\0");
			ft_printf("%s\n", str);
			free(str);
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

