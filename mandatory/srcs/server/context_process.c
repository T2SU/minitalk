/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:26 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:50:42 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	process_data(t_context *ctx, char dat)
{
	if (dat == '\0')
	{
		ft_putstr(ctx->content);
		context_reset(ctx, 0);
	}
	else
		buffer_append(&ctx->content, dat);
}

void	context_process(t_context *ctx)
{
	if (ctx->data.op == kOp_Data)
	{
		process_data(ctx, ctx->last.dat);
		ctx->last = ctx->data;
	}
	else
		ctx->last = ctx->data;
	ctx->data.op = kOp_Ack;
	context_send(ctx->data);
}
