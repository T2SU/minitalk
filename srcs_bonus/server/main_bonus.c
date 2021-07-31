/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:04 by smun              #+#    #+#             */
/*   Updated: 2021/07/31 21:34:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include <unistd.h>
#include <signal.h>

int	main(void)
{
	print_title(kServer);
	context_register(kServer);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (TRUE)
		sleep(-1);
	return (0);
}
