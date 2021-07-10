/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:04 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 19:53:01 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

int	main(void)
{
	context_register();
	ft_putstr("Server PID:");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (TRUE)
		sleep(-1);
	return 0;
}
