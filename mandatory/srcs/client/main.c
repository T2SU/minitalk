/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:04 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 02:58:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		ft_exit(EXIT_FAILURE, "Invalid argument.\n"
			"./client <Server PID> <String to send>");
	if (!ft_atoi_strict(argv[1], &pid))
		ft_exit(EXIT_FAILURE, "Unparsable server pid.");
	context_register(kClient);
	context_set_data((pid_t)pid, argv[2], ft_strlen(argv[2]) + 1);
	while (TRUE)
		sleep(-1);
	return (0);
}
