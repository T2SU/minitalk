/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:07:08 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 17:07:37 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}
