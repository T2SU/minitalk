/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:36:46 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 18:20:12 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static t_context	*get_context(void)
{
	static t_context	ctx;

	return (&ctx);
}

#include <stdio.h>

static void	handle_server(int signal, siginfo_t *si, void *uctx)
{
	t_context	*ctx;
	pid_t		opponent;

	(void)uctx;
	ctx = get_context();
	ctx->timeout = 0;
	if (ctx->opponent == 0)
		context_reset(ctx, si->si_pid);
	if (!context_is_opponent_pid(ctx, si))
		return ;
	opponent = ctx->opponent;
	context_append(ctx, signal);
	if (context_is_finished_receiving(ctx))
		context_on_finish(ctx);
	else
		ft_kill(opponent, SIGUSR1);
}

static void	handle_client(int signal, siginfo_t *si, void *uctx)
{
	pid_t		pid;
	t_context	*ctx;
	char		bit;

	(void)uctx;
	ctx = get_context();
	pid = ctx->opponent;
	if (!context_is_opponent_pid(ctx, si))
		return ;
	ctx->timeout = 0;
	if (signal == SIGUSR2)
		(ctx->data_idx)--;
	bit = ft_getbit(ctx->data, ctx->data_idx);
	context_verbose_print_bit((ctx->data_idx)++, bit);
	if (ctx->data_idx / 8 == ctx->data_len)
		context_on_finish(ctx);
	if (bit == 1)
		ft_kill(pid, SIGUSR1);
	else
		ft_kill(pid, SIGUSR2);
}

void	context_register(int mode)
{
	t_context			*ctx;
	struct sigaction	sa;

	ctx = get_context();
	ctx->mode = mode;
	context_reset(ctx, 0);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	if (mode == kServer)
		sa.sa_sigaction = &handle_server;
	else
		sa.sa_sigaction = &handle_client;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

void	context_set_data(pid_t opponent, void *data, int len)
{
	t_context	*ctx;

	ctx = get_context();
	ctx->data_idx = 0;
	ctx->data_len = len;
	ctx->data = (char *)data;
	ctx->opponent = opponent;
	handle_client(SIGUSR1, NULL, NULL);
}
