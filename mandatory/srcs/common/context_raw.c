/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_raw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:36:46 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 18:42:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>

static void		handle_signal(int signal)
{
	(void)signal;
}

t_bool			context_register(void)
{
	sigset_t	sig;

	sigemptyset(&sig);
	handle_signal(1);
	return (TRUE);
}
