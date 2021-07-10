/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:36:46 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 22:01:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stddef.h>

static t_context	*get_context(void)
{
	static t_context	ctx;

	return (&ctx);
}

static void	handle_signal(int signal, siginfo_t *si, void *uctx)
{
	t_context	*ctx;
	
	(void)uctx;
	ctx = get_context();
	if (ctx->opponent > 0 && ctx->opponent != si->si_pid)
		context_reset(ctx, ctx->opponent);
	context_append(ctx, signal);
	if (!context_is_filled(ctx))
		return ;
	context_process(ctx);
}

void	context_register(int mode, int op, char *content)
{
	t_context			*ctx;
	struct sigaction	sa;

	ctx = get_context();
	ctx->mode = mode;
	ctx->opponent = op;
	ctx->content = content;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	context_send(t_data data)
{
	const char	*dat = (char *)&data;
	t_context	*ctx;
	size_t		i;
	char		temp;

	ctx = get_context();
	ctx->data = data;
	i = 0;
	while (i < 8 * sizeof(t_data))
	{
		temp = dat[i / 8];
		temp = (temp >> (i & 7)) & 0x01;
		if (temp == 1)
			kill(ctx->opponent, SIGUSR1);
		else
			kill(ctx->opponent, SIGUSR2);
		i++;
	}
}
