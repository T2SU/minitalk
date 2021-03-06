/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_on_finish_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:26 by smun              #+#    #+#             */
/*   Updated: 2021/07/31 21:34:13 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include <unistd.h>
#include <stdlib.h>

/*
** Print received string,
** and switch to client mode for sending crc32.
*/

static void	phase1_on_server_finish(t_context *ctx, const pid_t pid)
{
	unsigned int	crc;

	write(STDOUT_FILENO, ctx->data, (ctx->data_idx / 8) - 1);
	ft_putstr("\n");
	crc = ft_crc32(ctx->data, ctx->data_idx / 8, 0);
	context_register(kClient);
	if (!buffer_expand(&ctx->data, 0, 4))
		ft_exit(EXIT_FAILURE, "Out of memory");
	ft_memcpy(&ctx->data[0], &crc, sizeof(unsigned int));
	context_set_data(pid, ctx->data, sizeof(unsigned int));
}

/*
** After sending crc32,
** reswitch to server mode for another client.
*/

static void	phase2_on_client_finish(t_context *ctx)
{
	ft_putstr("Sent crc32: ");
	ft_putnbr(*(int *)(&ctx->data[0]));
	ft_putstr("\n");
	context_register(kServer);
}

void	context_on_finish(t_context *ctx)
{
	const int	mode = ctx->mode;

	if (mode == kServer)
		phase1_on_server_finish(ctx, ctx->opponent);
	if (mode == kClient)
		phase2_on_client_finish(ctx);
}
