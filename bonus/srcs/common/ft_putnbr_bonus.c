/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:08 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 14:20:14 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include <unistd.h>

static int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static void	put_step(int n)
{
	char	c;

	if (n / 10)
		put_step(n / 10);
	c = '0' + ft_abs(n % 10);
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putnbr(const int nb)
{
	if (nb < 0)
		write(STDOUT_FILENO, "-", 1);
	put_step(nb);
}
