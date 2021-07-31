/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crc32.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:19:41 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 02:19:14 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** ref: http://web.mit.edu/freebsd/head/sys/libkern/crc32.c
*/

static void	make_crc_table(unsigned int *table, int id)
{
	int				i;
	int				j;
	unsigned int	k;

	i = 0;
	while (i < 256)
	{
		k = i;
		j = 0;
		while (j < 8)
		{
			if ((k & 1))
				k = (k >> 1) ^ id;
			else
				k >>= 1;
			j++;
		}
		table[i] = k;
		i++;
	}
}

unsigned int	ft_crc32(const char *mem, int length, unsigned int crc)
{
	static unsigned int	table[256];

	if (!table[255])
		make_crc_table(table, 0xEDB88320);
	crc = ~crc;
	while (length-- > 0)
		crc = table[(crc ^ *(mem++)) & 0xFF] ^ (crc >> 8);
	return (~crc);
}
