/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:08 by smun              #+#    #+#             */
/*   Updated: 2021/07/31 21:34:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include <unistd.h>

void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

void	ft_puterr(const char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
}
