/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 00:07:18 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 00:10:20 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
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
