/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:36:46 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 19:54:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stddef.h>

static void		handle_signal(int signal, siginfo_t *si, void *ctx)
{
	(void)si;
	(void)ctx;
	if (signal == SIGUSR1)
		ft_putstr("sig usr1\n");
	if (signal == SIGUSR2)
		ft_putstr("sig usr2\n");
}

void			context_register(void)
{
	struct sigaction	sa;

	sigfillset(&sa.sa_mask);
	sigdelset(&sa.sa_mask, SIGUSR1);
	sigdelset(&sa.sa_mask, SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
