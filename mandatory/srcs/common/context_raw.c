/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:06:50 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 23:50:32 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	context_reset(t_context *ctx, int opponent)
{
	ctx->opponent = opponent;
	ctx->timeout = 0;
	ctx->data_idx = 0;
	ctx->data_len = 0;
	free(ctx->data);
	ctx->data = NULL;
}

void	context_append(t_context *ctx, int signal)
{
	unsigned char	*pdata;
	unsigned char	bit;
	int				current_len;
	int				required_len;

	if (signal == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	current_len = (ctx->data_idx + 7) / 8;
	required_len = (ctx->data_idx + 8) / 8;
	if (!buffer_expand(&ctx->data, current_len, required_len))
		exit(EXIT_FAILURE);
	pdata = (unsigned char*)&ctx->data[ctx->data_idx / 8];
	*pdata |= (unsigned char)(bit << (ctx->data_idx & 7));
	ctx->data_idx++;
	ctx->timeout = 0;
}

t_bool	context_is_finished_receiving(t_context *ctx)
{
	if (ctx->data_idx < 8)
		return (FALSE);
	if ((ctx->data_idx & 7))
		return (FALSE);
	if (ctx->data[(ctx->data_idx / 8) - 1] != 0)
		return (FALSE);
	return (TRUE);
}
