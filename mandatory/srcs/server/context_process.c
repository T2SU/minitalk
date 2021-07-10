/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:26 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 23:16:46 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

void	context_process(t_context *ctx)
{
	write(STDOUT_FILENO, ctx->data, ctx->data_idx / 8);
	context_reset(ctx, 0);
}
