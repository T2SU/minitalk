/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:51:15 by smun              #+#    #+#             */
/*   Updated: 2021/07/10 17:37:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# define TRUE 1
# define FALSE 0
# ifndef FRAGMENT_SIZE
#  define FRAGMENT_SIZE 32
# endif
# ifndef RTO
#  define RTO 100
# endif

typedef int	t_bool;

enum	e_op
{
	kOp_Hello,
	kOp_Data,
	kOp_Retrans,
	kOp_Finish
};

typedef struct s_header
{
	int				seq;
	char			opcode;
	char			dir;
	int				sender;
	int				length;
	unsigned int	checksum;
}					t_header;

typedef struct s_data
{
	t_header	header;
	char		content[FRAGMENT_SIZE];
}				t_data;

typedef struct s_context
{
	int		opponent;
	char	*content;
	int		data_idx;
	char	data[sizeof(t_data)];
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
**      srcs/common/ft_crc32.c
**  ===========================================
*/

unsigned int	ft_crc32(const char *mem, int length, unsigned int crc);

/*
**  ===========================================
**      srcs/common/context_raw.c
**  ===========================================
*/

t_bool			context_register(void);

/*
**  ===========================================
**      srcs/common/context_process.c
**  ===========================================
*/

t_bool			context_process(const t_data *dat);

#endif
