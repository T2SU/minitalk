/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:15 by smun              #+#    #+#             */
/*   Updated: 2021/07/31 22:22:43 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_BONUS_H
# define COMMON_BONUS_H
# include <stddef.h>
# include <signal.h>
# define TRUE 1
# define FALSE 0
# ifndef VERBOSE
#  define VERBOSE 0
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
**      srcs/common/ft_kill.c
**  ===========================================
*/

void			ft_kill(const pid_t pid, int signal);

/*
**  ===========================================
**      srcs/common/ft_bit.c
**  ===========================================
*/

char			ft_getbit(const char *data, int bitindex);
void			ft_setbit(char *data, int bitindex, char bit);

/*
**  ===========================================
**      srcs/common/context_retrans.c
**  ===========================================
*/

void			context_retrans(t_context *ctx);

/*
**  ===========================================
**      srcs/common/context_pid.c
**  ===========================================
*/

t_bool			context_is_opponent_pid(t_context *ctx, siginfo_t *si);

/*
**  ===========================================
**      srcs/common/title.c
**  ===========================================
*/

void			print_title(int mode);

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
**      srcs/common/context_verbose.c
**  ===========================================
*/

void			context_verbose_print_bit(int idx, unsigned char bit);

/*
**  ===========================================
**      srcs/client/context_on_finish.c
**      srcs/server/context_on_finish.c
**  ===========================================
*/

void			context_on_finish(t_context *ctx);

#endif
