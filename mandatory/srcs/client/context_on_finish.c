/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_on_finish.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:56:39 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 15:55:25 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

/*
** After sending string,
** Switch to server mode for receiving crc32.
*/

static void	phase1_on_client_finish(t_context *ctx, const pid_t pid)
{
	ft_putstr(ctx->data);
	ft_putstr("\n");
	ctx->data = NULL;
	context_register(kServer);
	ctx->opponent = pid;
	ctx->data_expected_len = sizeof(unsigned int);
}

/*
** On finish receving crc32.
** Print received crc32 data.
** Then, exit client app and return to shell.
*/

static void	phase2_on_server_finish(t_context *ctx)
{
	ft_putstr("Received crc32: ");
	ft_putnbr(*(int *)ctx->data);
	ft_putstr("\n");
	context_reset(ctx, 0);
	ft_exit(EXIT_SUCCESS, NULL);
}

void	context_on_finish(t_context *ctx)
{
	const int	mode = ctx->mode;

	if (mode == kClient)
		phase1_on_client_finish(ctx, ctx->opponent);
	if (mode == kServer)
		phase2_on_server_finish(ctx);
}
