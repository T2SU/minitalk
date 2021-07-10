/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:56:39 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 23:53:05 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

void	context_process(t_context *ctx)
{
	ft_putstr("Sent successfully ");
	ft_putnbr(ctx->data_len);
	ft_putstr(" bytes!\n");
	exit(EXIT_SUCCESS);
}
