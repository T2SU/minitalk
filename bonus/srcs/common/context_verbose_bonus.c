/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_verbose_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 02:29:52 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 14:19:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"

void	context_verbose_print_bit(int idx, unsigned char bit)
{
	if (!VERBOSE)
		return ;
	ft_putnbr(idx);
	ft_putstr(": ");
	if (bit)
		ft_putstr("1\n");
	else
		ft_putstr("0\n");
}
