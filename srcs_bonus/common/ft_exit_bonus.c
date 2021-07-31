/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:07:18 by smun              #+#    #+#             */
/*   Updated: 2021/07/31 21:33:57 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include <stdlib.h>

void	ft_exit(int code, const char *err)
{
	if (err != NULL)
	{
		ft_puterr(err);
		ft_puterr("\n");
	}
	exit(code);
}
