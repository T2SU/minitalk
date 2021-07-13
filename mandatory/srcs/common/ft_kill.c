/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 14:49:34 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 18:13:18 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <signal.h>
#include <stdlib.h>

void	ft_kill(const pid_t pid, int signal)
{
	const int	ret_value = kill(pid, signal);

	if (ret_value != 0)
		ft_exit(EXIT_FAILURE, "Failed to send signal");
}
