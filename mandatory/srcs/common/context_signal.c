/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:36:46 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 00:57:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stddef.h>
#include <stdlib.h>

static t_context	*get_context(void)
{
	static t_context	ctx;

	return (&ctx);
}

static void	handle_server(int signal, siginfo_t *si, void *uctx)
{
	t_context	*ctx;
	pid_t		opponent;
	
	(void)uctx;
	ctx = get_context();
	if (ctx->opponent == 0)
		context_reset(ctx, si->si_pid);
	opponent = ctx->opponent;
	context_append(ctx, signal);
	if (context_is_finished_receiving(ctx))
		context_process(ctx);
	kill(opponent, SIGUSR1);
}

static void	handle_client(int signal, siginfo_t *si, void *uctx)
{
	t_context	*ctx;
	char		temp;

	(void)uctx;
	ctx = get_context();
	if (signal != SIGUSR1 || (si != NULL && ctx->opponent != si->si_pid))
		return ;
	temp = ctx->data[ctx->data_idx / 8];
	temp = (temp >> (ctx->data_idx & 7)) & 0x01;
	if (temp == 1)
		kill(ctx->opponent, SIGUSR1);
	else
		kill(ctx->opponent, SIGUSR2);
	ft_putnbr(ctx->data_idx);
	ft_putstr(": ");
	if (temp)
		ft_putstr("1\n");
	else
		ft_putstr("0\n");
	(ctx->data_idx)++;
	if (ctx->data_idx / 8 == ctx->data_len)
		context_process(ctx);
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
