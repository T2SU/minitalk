# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 16:44:23 by smun              #+#    #+#              #
#    Updated: 2021/07/13 18:20:22 by smun             ###   ########.fr        #
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
	srcs/common/buffer \
	srcs/common/ft_putstr \
	srcs/common/ft_putnbr \
	srcs/common/ft_strlen \
	srcs/common/ft_memcpy \
	srcs/common/ft_crc32 \
	srcs/common/ft_atoi_strict \
	srcs/common/ft_exit \
	srcs/common/ft_kill \
	srcs/common/ft_bit \
	srcs/common/title \
	srcs/common/context_raw \
	srcs/common/context_signal \
	srcs/common/context_verbose \
	srcs/common/context_pid
COMMON_FILES_SRC = $(addsuffix .c, $(COMMON_FILES))
COMMON_FILES_OBJ = $(COMMON_FILES_SRC:.c=.o)

SVR_FILES = \
	srcs/server/main \
	srcs/server/context_on_finish
SVR_FILES_SRC = $(addsuffix .c, $(SVR_FILES))
SVR_FILES_OBJ = $(SVR_FILES_SRC:.c=.o)

CLI_FILES = \
	srcs/client/main \
	srcs/client/context_on_finish
CLI_FILES_SRC = $(addsuffix .c, $(CLI_FILES))
CLI_FILES_OBJ = $(CLI_FILES_SRC:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

all : $(NAME_CLIENT) $(NAME_SERVER)

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

.PHONY: all clean fclean re $(NAME_SERVER) $(NAME_CLIENT)
