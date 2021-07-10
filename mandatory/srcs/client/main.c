/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:04 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:51:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (EXIT_FAILURE);
	if (!ft_atoi_strict(argv[1], &pid))
		return (EXIT_FAILURE);
	context_register(kClient, pid, argv[2]);
	context_send((t_data){kOp_Data, argv[2][0]});
	while (TRUE)
	{
		usleep(10000);
	}
	return 0;
}
