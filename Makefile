# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 16:44:23 by smun              #+#    #+#              #
#    Updated: 2021/07/31 22:24:26 by smun             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Debug compilation
ifeq ($(DEBUG),1)
	CFLAGS += -g -DVERBOSE=1
endif

INC = -I./includes
INC_BONUS = -I./includes_bonus

SRC_DIR = srcs/
SRC_BONUS_DIR = srcs_bonus/

COMMON_FILES = \
	common/buffer \
	common/ft_putstr \
	common/ft_putnbr \
	common/ft_strlen \
	common/ft_memcpy \
	common/ft_crc32 \
	common/ft_atoi_strict \
	common/ft_exit \
	common/ft_kill \
	common/ft_bit \
	common/title \
	common/context_raw \
	common/context_signal \
	common/context_verbose \
	common/context_pid
COMMON_FILES_SRC = $(addsuffix .c, $(addprefix $(SRC_DIR), $(COMMON_FILES)))
COMMON_FILES_OBJ = $(COMMON_FILES_SRC:.c=.o)
COMMON_FILES_SRC_BONUS = $(addsuffix .c, $(addsuffix _bonus, $(addprefix $(SRC_BONUS_DIR), $(COMMON_FILES))))
COMMON_FILES_OBJ_BONUS = $(COMMON_FILES_SRC_BONUS:.c=.o)

SVR_FILES = \
	server/main \
	server/context_on_finish
SVR_FILES_SRC = $(addsuffix .c, $(addprefix $(SRC_DIR), $(SVR_FILES)))
SVR_FILES_OBJ = $(SVR_FILES_SRC:.c=.o)
SVR_FILES_SRC_BONUS = $(addsuffix .c, $(addsuffix _bonus, $(addprefix $(SRC_BONUS_DIR), $(SVR_FILES))))
SVR_FILES_OBJ_BONUS = $(SVR_FILES_SRC_BONUS:.c=.o)

CLI_FILES = \
	client/main \
	client/context_on_finish
CLI_FILES_SRC = $(addsuffix .c, $(addprefix $(SRC_DIR), $(CLI_FILES)))
CLI_FILES_OBJ = $(CLI_FILES_SRC:.c=.o)
CLI_FILES_SRC_BONUS = $(addsuffix .c, $(addsuffix _bonus, $(addprefix $(SRC_BONUS_DIR), $(CLI_FILES))))
CLI_FILES_OBJ_BONUS = $(CLI_FILES_SRC_BONUS:.c=.o)

NAME_CLIENT = client
NAME_SERVER = server

all : $(NAME_CLIENT) $(NAME_SERVER)

bonus : $(COMMON_FILES_OBJ_BONUS) $(SVR_FILES_OBJ_BONUS) $(CLI_FILES_OBJ_BONUS)
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(COMMON_FILES_OBJ_BONUS) $(CLI_FILES_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(COMMON_FILES_OBJ_BONUS) $(SVR_FILES_OBJ_BONUS)

clean :
	rm -rf $(COMMON_FILES_OBJ) $(SVR_FILES_OBJ) $(CLI_FILES_OBJ) \
		$(COMMON_FILES_OBJ_BONUS) $(SVR_FILES_OBJ_BONUS) $(CLI_FILES_OBJ_BONUS)

fclean : clean
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all

%.o : %.c
ifeq ($(MAKECMDGOALS),bonus)
	$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@
else
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
endif

$(NAME_SERVER) : $(COMMON_FILES_OBJ) $(SVR_FILES_OBJ)
	rm -rf $@
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_CLIENT) : $(COMMON_FILES_OBJ) $(CLI_FILES_OBJ)
	rm -rf $@
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: all clean fclean re bonus $(NAME_SERVER) $(NAME_CLIENT)
