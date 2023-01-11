/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clt_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:54:27 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/11 13:12:36 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//void	ft_putnbr_base(unsigned long nb, unsigned long len, \
//	char *base, int *size)
//{
//	if (nb < 0)
//	{
//		ft_putchar('-', size);
//		nb = nb * (-1);
//		ft_putnbr_base(nb, len, base, size);
//	}
//	else if (nb / len)
//	{
//		ft_putnbr_base(nb / len, len, base, size);
//		ft_putchar(base[nb % len], size);
//	}
//	else
//		ft_putchar(base[nb % len], size);
//}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*str;

	if (argc != 3)
		return (ft_printf("Error\ninvalid number of args\n"));
	pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		ft_printf("%i\n", (int)str[i]);
		i++;
	}
}
