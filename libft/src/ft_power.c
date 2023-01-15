/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:46:56 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 00:47:43 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

size_t	ft_pwr(int i, int pwr)
{
	size_t	pawa;

	pawa = 1;
	while (i > 0)
	{
		pawa = pawa * pwr;
		i--;
	}
	return (pawa);
}
