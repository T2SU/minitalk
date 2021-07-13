# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 16:44:23 by smun              #+#    #+#              #
#    Updated: 2021/07/13 14:52:03 by smun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Debug compilation
ifeq ($(DEBUG),1)
	CFLAGS += -g -DVERBOSE=1
endif

INC = -I./includes

COMMON_FILES = \
	srcs/common/buffer_bonus \
	srcs/common/ft_putstr_bonus \
	srcs/common/ft_putnbr_bonus \
	srcs/common/ft_strlen_bonus \
	srcs/common/ft_memcpy_bonus \
	srcs/common/ft_crc32_bonus \
	srcs/common/ft_atoi_strict_bonus \
	srcs/common/ft_exit_bonus \
	srcs/common/ft_kill_bonus \
	srcs/common/context_raw_bonus \
	srcs/common/context_signal_bonus \
	srcs/common/context_verbose_bonus
COMMON_FILES_SRC = $(addsuffix .c, $(COMMON_FILES))
COMMON_FILES_OBJ = $(COMMON_FILES_SRC:.c=.o)

SVR_FILES = \
	srcs/server/main_bonus \
	srcs/server/context_on_finish_bonus
SVR_FILES_SRC = $(addsuffix .c, $(SVR_FILES))
SVR_FILES_OBJ = $(SVR_FILES_SRC:.c=.o)

CLI_FILES = \
	srcs/client/main_bonus \
	srcs/client/context_on_finish_bonus
CLI_FILES_SRC = $(addsuffix .c, $(CLI_FILES))
CLI_FILES_OBJ = $(CLI_FILES_SRC:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

all : $(NAME_CLIENT) $(NAME_SERVER)

bonus : all

clean :
	rm -rf $(COMMON_FILES_OBJ) $(SVR_FILES_OBJ) $(CLI_FILES_OBJ)

fclean : clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME_SERVER) : $(COMMON_FILES_OBJ) $(SVR_FILES_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT) : $(COMMON_FILES_OBJ) $(CLI_FILES_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all clean fclean re $(NAME_SERVER) $(NAME_CLIENT) bonus
