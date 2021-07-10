/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:15 by smun              #+#    #+#             */
/*   Updated: 2021/07/11 02:24:23 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <stddef.h>
# include <signal.h>
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

typedef struct s_context
{
	int		mode;
	pid_t	opponent;
	char	*data;
	int		data_len;
	int		data_idx;
	int		data_expected_len;
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
void			ft_puterr(const char *str);

/*
**  ===========================================
**      srcs/common/ft_putnbr.c
**  ===========================================
*/

void			ft_putnbr(const int nb);

/*
**  ===========================================
**      srcs/common/ft_exit.c
**  ===========================================
*/

void			ft_exit(int code, const char *err);

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

t_bool			buffer_expand(char **pdata, int current_len, int desired_len);

/*
**  ===========================================
**      srcs/common/context_signal.c
**  ===========================================
*/

void			context_register(int mode);
void			context_set_data(pid_t opponent, void *data, int len);

/*
**  ===========================================
**      srcs/common/context_raw.c
**  ===========================================
*/

void			context_reset(t_context *ctx, int opponent);
void			context_append(t_context *ctx, int signal);
t_bool			context_is_finished_receiving(t_context *ctx);

/*
**  ===========================================
**      srcs/client/context_process.c
**      srcs/server/context_process.c
**  ===========================================
*/

void			context_process(t_context *ctx);

#endif
