/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:04 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 18:19:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

static void	print_argument_info(char *str, int slen)
{
	ft_putstr("String Bytes: ");
	ft_putnbr(slen);
	ft_putstr(", calculated crc32: ");
	ft_putnbr((int)ft_crc32(str, slen, 0u));
	ft_putstr("\n");
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	slen;

	if (argc != 3)
		ft_exit(EXIT_FAILURE, "Invalid argument.\n"
			"./client <Server PID> <String to send>");
	if (!ft_atoi_strict(argv[1], &pid))
		ft_exit(EXIT_FAILURE, "Unparsable server pid.");
	slen = ft_strlen(argv[2]) + 1;
	print_title(kClient);
	print_argument_info(argv[2], slen);
	context_register(kClient);
	context_set_data((pid_t)pid, argv[2], slen);
	while (TRUE)
		sleep(-1);
	return (0);
}
