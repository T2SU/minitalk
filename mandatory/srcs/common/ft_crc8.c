/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crc8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 20:37:05 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 20:39:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

unsigned char	ft_crc8(char *data, int len)
{
	unsigned char	crc;
	int				i;
	int				j;

	crc = 0xff;
	i = 0;
	while (i < len)
	{
		crc ^= (unsigned char)data[i];
		j = 0;
		while (j < 8)
		{
			if ((crc & 0x80))
				crc = (unsigned char)((crc << 1) ^ 0x31);
			else
				crc <<= 1;
			j++;
		}
		i++;
	}
	return (crc);
}
