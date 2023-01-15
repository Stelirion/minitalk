/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngennaro <ngennaro@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:02:33 by ngennaro          #+#    #+#             */
/*   Updated: 2023/01/15 06:44:35 by ngennaro         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"
# include "libft/headers/get_next_line_bonus.h"

typedef struct s_sig
{
	size_t	chain;
	char	new[8];
	char	len[64];
	int		byte;
	int		size;
	char	*str;
}			t_sig;



#endif
