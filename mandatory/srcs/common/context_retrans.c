/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_retrans.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:59:56 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 17:03:50 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	context_retrans(t_context *ctx)
{
	if (ctx->opponent == 0)
		return ;
	(ctx->timeout)++;
	if (ctx->timeout >= RTO)
	{
		ft_putstr("RTO reached. send retrans signal..\n");
		ft_kill(ctx->opponent, SIGUSR2);
		ctx->timeout = 0;
	}
}
