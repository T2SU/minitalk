/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:49:34 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 14:51:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stdlib.h>

void	ft_kill(const pid_t pid, int signal)
{
	const int	ret_value = kill(pid, signal);

	if (ret_value == -1)
		ft_exit(EXIT_FAILURE, "Failed to send signal");
}
