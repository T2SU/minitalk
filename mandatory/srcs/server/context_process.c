/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:26 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 01:22:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>
#include <stdlib.h>

void	context_process(t_context *ctx)
{
	const pid_t		pid = ctx->opponent;
	unsigned int	crc;

	if (ctx->mode == kServer)
	{
		write(STDOUT_FILENO, ctx->data, (ctx->data_idx / 8) - 1);
		crc = ft_crc32(ctx->data, ctx->data_idx / 8, 0);
		context_register(kClient);
		if (!buffer_expand(&ctx->data, 0, 4))
			ft_exit(EXIT_FAILURE, "Out of memory");
		*(unsigned int *)(&ctx->data[0]) = crc;
		ctx->data_len = sizeof(unsigned int);
		ctx->data_idx = 0;
		ctx->opponent = pid;
		ft_putstr("\n");
	}
	else
	{
		ft_putstr("Sent crc32 ack: ");
		ft_putnbr(*(int *)(&ctx->data[0]));
		ft_putstr("\n");
		kill(pid, SIGUSR1);
		context_register(kServer);
	}
}
