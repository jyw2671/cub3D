# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 22:35:39 by yjung             #+#    #+#              #
#    Updated: 2021/02/18 16:11:15 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

AR = ar
ARFLAGS = crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -f

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(addprefix $(INC_DIR)/, \
	libft.h	\
	ft_string.h	\
	ft_libft_type.h	\
	ft_math.h	\
	ft_memory.h	\
	get_next_line.h	\
	ft_lst_type.h	\
	ft_lst.h	\
)

SRC_MATH_DIR = $(SRC_DIR)/math
SRC_MATH = $(addprefix $(SRC_MATH_DIR)/, \
	ft_pow.c	\
	ft_max.c	\
)

SRC_MEMORY_DIR = $(SRC_DIR)/memory
SRC_MEMORY = $(addprefix $(SRC_MEMORY_DIR)/, \
	ft_memcpy.c	\
	ft_memmove.c	\
	ft_memset.c	\
)

SRC_STRING_DIR = $(SRC_DIR)/string
SRC_STRING = $(addprefix $(SRC_STRING_DIR)/, \
	ft_strchr.c	\
	ft_strjoin.c	\
	ft_strlen.c	\
	ft_strcmp.c	\
	ft_split_cnt.c	\
	ft_strndup.c	\
)

SRC_GNL_DIR = $(SRC_DIR)/get_next_line
SRC_GNL = $(addprefix $(SRC_GNL_DIR)/, \
	get_next_line.c	\
)

SRC_LST_DIR = $(SRC_DIR)/lst
SRC_LST = $(addprefix $(SRC_LST_DIR)/, \
	ft_lstadd_back.c	\
	ft_lstclear.c	\
	ft_lstlast.c	\
	ft_lstnew.c	\
	ft_lstsize.c	\
)

SRCS = \
	$(SRC_MATH)	\
	$(SRC_MEMORY)	\
	$(SRC_STRING)	\
	$(SRC_GNL)	\
	$(SRC_LST)

vpath %.c \
	$(SRC_DIR)	\
	$(SRC_MATH_DIR)	\
	$(SRC_MEMORY_DIR)	\
	$(SRC_STRING_DIR)	\
	$(SRC_GNL_DIR)	\
	$(SRC_LST_DIR)

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(HEADERS) $(OBJS)
	@$(AR) $(ARFLAGS) $@ $(OBJS)

.PHONY: all clean fclean re
