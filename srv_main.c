/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srv_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:23:52 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/11 15:59:49 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*test(int chr)
{
	ft_printf("%c", chr);
	return ((void *)chr);
}

int	main(void)
{
	ft_printf("PID : %i\n", getpid());
	signal(SIGUSR1, test('1'));
	signal(SIGUSR2, test('2'));
	while (1)
		pause();
	return (0);
}
