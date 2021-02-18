# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 18:16:35 by yjung             #+#    #+#              #
#    Updated: 2021/02/18 16:07:29 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# libft
LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_INC_DIR)

# minilibx
MLX = libmlx.dylib
MLX_DIR = lib/minilibx_mms_20200219
MLX_FLAGS = -L./$(MLX_DIR) -lmlx
MLX_CP = cp $(MLX_FILE) $(MLX)
MLX_RM = rm -f $(MLX)
MLX_FILE = $(MLX_DIR)/$(MLX)
MLX_INC_DIR = $(MLX_DIR)
CFLAGS += -I $(MLX_INC_DIR)

RM = rm
RMFLAGS = -f

INC_DIR = include
CFLAGS += -I $(INC_DIR)
SRC_DIR = src
OBJ_DIR = obj

HEADERS = $(wildcard $(INC_DIR)/*.h)

# MINILIBX_DIR = $(SRC_DIR)/minilibx_tool
# MINILIBX_SRCS = $(wildcard $(MINILIBX_DIR)/*.c)

SRCS = \
	$(wildcard $(SRC_DIR)/*.c)
	# $(MINILIBX_SRCS)

vpath %.c \
	$(SRC_DIR)
	# $(MINILIBX_DIR)

SRCS += $(wildcard $(SRC_DIR)/dummy_mac/*.c)
vpath %.c $(SRC_DIR)/dummy_mac

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean $(LIBFT)_fclean $(MLX)_clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(NAME) : cub3d.c $(MLX_FILE) $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) $(CINCLUDES) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)

test : $(NAME)
	@./cub3D

# Libft
$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

$(LIBFT)_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

$(LIBFT)_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean

# minilibx
$(MLX) : $(MLX_FILE)

$(MLX_FILE) :
	$(MLX_SUBMODULE)
	@$(MLX_NOTIC)
	@make --no-print-directory -C $(MLX_DIR)
	@$(MLX_CP)

$(MLX)_clean :
	@make --no-print-directory -C $(MLX_DIR) clean
	@$(MLX_RM)

.PHONY: all clean fclean re test\
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	$(MLX) $(MLX)_clean
