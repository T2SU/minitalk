/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 15:11:01 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 15:48:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** getbit mechanism.
**
** eg) "ab", bitindex = 4
**
** +---------+---------+
** |    a    |    b    |
** +---------+---------+
**  0x61      0x62
**  0110 0001 0110 0010
**     ^
**     bitindex = 4
**
**  bitindex(4) / 8 = 0
**    -> const char ch = data[0];
**
**  bitindex(4) & 7 = 4
**    -> shifted = ch >> 4;
**    -> shifted = data[0] >> 4;
*/

char	ft_getbit(const char *data, int bitindex)
{
	const char	ch = data[bitindex / 8];
	char		shifted;

	shifted = ch >> (bitindex & 7);
	return (shifted & 0x01);
}

/*
** setbit mechanism
**
** eg) bitindex = 7, bit = 1
**
** +---------+---------+
** |         |         |
** +---------+---------+
**  0000 0000 0000 0000
**  ^
**  bitindex = 7
**
**  unsigned char *pdata = (unsigned char *)data;
**
**  * pdata[bitindex(7) / 8] |= (bit << (bitindex(7) & 7));
**
**  bitindex(7) / 8 = 0,
**  bitindex(7) & 7 = 7
**    -> pdata[0] |= (bit << 7);
**
**  [[ After ]]
**
** +---------+---------+
** |         |         |
** +---------+---------+
**  1000 0000 0000 0000
**  ^
*/

void	ft_setbit(char *data, int bitindex, char bit)
{
	const unsigned char	ubit = (const unsigned char)bit;
	unsigned char *pdata;

	pdata = (unsigned char *)data;
	pdata[bitindex / 8] |= (unsigned char)(ubit << (bitindex & 7));
}
