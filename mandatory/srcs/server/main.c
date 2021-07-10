/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:04 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:47:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>
#include <signal.h>

int	main(void)
{
	context_register(kServer, 0, NULL);
	ft_putstr("Server PID:");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (TRUE)
	{
		usleep(10000);
	}
	return 0;
}
