/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:15 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 21:50:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stddef.h>
# define TRUE 1
# define FALSE 0
# ifndef FRAGMENT_SIZE
#  define FRAGMENT_SIZE 32
# endif
# ifndef RTO
#  define RTO 100
# endif

typedef int	t_bool;

enum	e_mode
{
	kClient,
	kServer
};

/*
** 1. Client -> Server
**     kOp_Data | Data[0]
**
** 2. Server -> Client
**     kOp_Ack | Data[0]
**
** 3-1. Client -> Server (Retransmission) (If Data is not delivered properly)
**     kRetrans | Data[0]
**
** 3-2. Server -> Client
**     kOp_Ack | Data[0]
**
** 4-1. Client -> Server (Next Data)
**     kOp_Data | Data[1]
**
** 4-2. Server -> Client (Next Data Ack)
**     kOp_Ack | Data[1]
**
**   ...
*/

enum	e_op
{
	kOp_Data,
	kOp_Retrans,
	kOp_Ack
};

typedef struct s_data
{
	char	op;
	char	dat;
}			t_data;

typedef struct s_context
{
	int		mode;
	int		opponent;
	char	*content;
	int		data_idx;
	t_data	data;
	t_data	last;
	int		timeout;
}			t_context;

/*
**  ===========================================
**      srcs/common/ft_strlen.c
**  ===========================================
*/

int				ft_strlen(const char *str);

/*
**  ===========================================
**      srcs/common/ft_putstr.c
**  ===========================================
*/

void			ft_putstr(const char *str);

/*
**  ===========================================
**      srcs/common/ft_putnbr.c
**  ===========================================
*/

void			ft_putnbr(const int nb);

/*
**  ===========================================
**      srcs/common/ft_crc8.c
**  ===========================================
*/

unsigned char	ft_crc8(char *data, int len);

/*
**  ===========================================
**      srcs/common/ft_crc32.c
**  ===========================================
*/

unsigned int	ft_crc32(const char *mem, int length, unsigned int crc);

/*
**  ===========================================
**      srcs/common/ft_memcpy.c
**  ===========================================
*/

void			*ft_memcpy(void *dst, const void *src, size_t n);

/*
**  ===========================================
**      srcs/common/ft_atoi_strict.c
**  ===========================================
*/

t_bool			ft_atoi_strict(const char *str, int *pvalue);

/*
**  ===========================================
**      srcs/common/buffer.c
**  ===========================================
*/

t_bool			buffer_append(char **pcontent, char ch);

/*
**  ===========================================
**      srcs/common/context_signal.c
**  ===========================================
*/

void			context_register(int mode, int op, char *content);
void			context_send(t_data data);

/*
**  ===========================================
**      srcs/common/context_raw.c
**  ===========================================
*/

void			context_reset(t_context *ctx, int opponent);
void			context_append(t_context *ctx, int signal);
t_bool			context_is_filled(t_context *ctx);

/*
**  ===========================================
**      srcs/client/context_process.c
**      srcs/server/context_process.c
**  ===========================================
*/

void			context_process(t_context *ctx);

#endif
