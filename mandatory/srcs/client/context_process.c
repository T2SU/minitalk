/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:56:39 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:59:50 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

void	context_process(t_context *ctx)
{
	if (ctx->data.op == kOp_Ack && ctx->data.dat == *(ctx->content))
	{
		if (ctx->data.dat == '\0')
			exit(EXIT_SUCCESS);
		ctx->data.op = kOp_Data;
		ctx->content++;
		ctx->data.dat = *(ctx->content);
	}
	else
		ctx->data.op = kOp_Retrans;
	context_send(ctx->data);
}
