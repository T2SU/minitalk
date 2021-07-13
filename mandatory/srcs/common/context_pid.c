/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_pid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 17:09:35 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 17:19:55 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <unistd.h>

t_bool	context_is_opponent_pid(t_context *ctx, siginfo_t *si)
{
	if (ctx->opponent == 0)
		return (FALSE);
	if (si != NULL && ctx->opponent != si->si_pid)
		return (FALSE);
	return (TRUE);
}

t_bool	is_self_pid(siginfo_t *si)
{
	if (si == NULL)
		return (FALSE);
	if (getpid() != si->si_pid)
		return (FALSE);
	return (TRUE);
}
