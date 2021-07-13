/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:12:25 by smun              #+#    #+#             */
/*   Updated: 2021/07/13 15:40:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

t_bool	buffer_expand(char *pdata[], int current_len, int desired_len)
{
	char	*new_buffer;

	if (desired_len <= current_len)
		return (TRUE);
	new_buffer = malloc(desired_len);
	if (!new_buffer)
		return (FALSE);
	new_buffer[desired_len - 1] = '\0';
	ft_memcpy(new_buffer, *pdata, current_len);
	free(*pdata);
	*pdata = new_buffer;
	return (TRUE);
}
