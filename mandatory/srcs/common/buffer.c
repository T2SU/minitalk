/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:12:25 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:24:22 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static t_bool	ensure_buffer(char **pcontent)
{
	int		len;
	char	*new_buffer;

	if (*pcontent == NULL)
		len = 0;
	else
		len = ft_strlen(*pcontent);
	new_buffer = malloc(len + sizeof(char) + sizeof(char));
	if (!new_buffer)
		return (FALSE);
	ft_memcpy(new_buffer, *pcontent, len);
	new_buffer[len] = '\0';
	free(*pcontent);
	*pcontent = new_buffer;
	return (TRUE);
}

t_bool	buffer_append(char **pcontent, char ch)
{
	int	len;

	if (!ensure_buffer(pcontent))
		return (FALSE);
	len = ft_strlen(*pcontent);
	(*pcontent)[len + 0] = ch;
	(*pcontent)[len + 1] = '\0';
	return (TRUE);
}
