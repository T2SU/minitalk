/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:56:39 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 01:00:20 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

void	context_process(t_context *ctx)
{
	const pid_t	pid = ctx->opponent;;

	if (ctx->mode == kClient)
	{
		ft_putstr("Sent successfully ");
		ft_putnbr(ctx->data_len);
		ft_putstr(" bytes!\n");
		ctx->data = NULL;
		context_register(kServer);
		ctx->opponent = pid;
		ctx->data_expected_len = 4;
		kill(pid, SIGUSR1);
	}
	else
	{
		ft_putstr("Received crc32: ");
		ft_putnbr(*(int *)(&ctx->data[0]));
		ft_putstr("\n");
		ft_exit(EXIT_SUCCESS, NULL);
	}
}
