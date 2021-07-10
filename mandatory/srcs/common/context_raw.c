/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:06:50 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:49:16 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stdlib.h>

void	context_reset(t_context *ctx, int opponent)
{
	ctx->opponent = opponent;
	ctx->timeout = 0;
	ctx->data_idx = 0;
	free(ctx->content);
	ctx->content = NULL;
}

void	context_append(t_context *ctx, int signal)
{
	unsigned char	*pdata;
	unsigned char	bit;

	if (signal == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	pdata = (unsigned char*)&ctx->data;
	pdata = &pdata[ctx->data_idx / 8];
	(*pdata) |= (unsigned char)(bit << (ctx->data_idx & 7));
	ctx->data_idx++;
	ctx->timeout = 0;
}

t_bool	context_is_filled(t_context *ctx)
{
	return (ctx->data_idx == 8 * sizeof(unsigned char) * sizeof(t_data));
}
