# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 18:16:35 by yjung             #+#    #+#              #
#    Updated: 2021/03/02 19:19:44 by yjung            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS = cub3D_bonus

CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# libft
LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_INC_DIR)
CFLAGS_B += -I $(LIBFT_INC_DIR)

# minilibx
MLX = libmlx.dylib
MLX_DIR = lib/minilibx_mms_20200219
MLX_FLAGS = -L./$(MLX_DIR) -lmlx
MLX_CP = cp $(MLX_FILE) $(MLX)
MLX_RM = rm -f $(MLX)
MLX_FILE = $(MLX_DIR)/$(MLX)
MLX_INC_DIR = $(MLX_DIR)
CFLAGS += -I $(MLX_INC_DIR)
CFLAGS_B += -I $(MLX_INC_DIR)

RM = rm
RMFLAGS = -f

INC_DIR = include
CFLAGS += -I $(INC_DIR)
SRC_DIR = src
OBJ_DIR = obj

INC_B_DIR = include_bonus
CFLAGS_B += -I $(INC_B_DIR)
SRC_B_DIR = src_bonus
OBJ_B_DIR = obj_bonus

HEADERS = $(wildcard $(INC_DIR)/*.h)
HEADERS_B = $(wildcard $(INC_B_DIR)/*.h)

SRCS = \
	$(wildcard $(SRC_DIR)/*.c)

SRCS_B = \
	$(wildcard $(SRC_B_DIR)/*.c)

vpath %.c \
	$(SRC_DIR) $(SRC_B_DIR)

SRCS += $(wildcard $(SRC_DIR)/dummy_mac/*.c)
SRCS_B += $(wildcard $(SRC_B_DIR)/dummy_mac/*.c)

vpath %.c \
	$(SRC_DIR)/dummy_mac $(SRC_B_DIR)/dummy_mac

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_B = $(addprefix $(OBJ_B_DIR)/, $(notdir $(SRCS_B:.c=.o)))

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJS)
	$(RM) -rf $(OBJ_DIR)

fclean : clean $(LIBFT)_fclean $(MLX)_clean
	@$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus : $(BONUS)

bonus_clean :
	@$(RM) $(RMFLAGS) $(OBJS_B)
	$(RM) -rf $(OBJ_B_DIR)

bonus_fclean : bonus_clean $(LIBFT)_fclean $(MLX)_clean
	@$(RM) $(RMFLAGS) $(BONUS)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_B_DIR)/%.o : %.c
	@mkdir -p $(OBJ_B_DIR)
	@$(CC) $(CFLAGS_B) -c $< -o $@

$(NAME) : cub3d.c $(MLX_FILE) $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(BONUS) : cub3d_bonus.c $(MLX_FILE) $(LIBFT_FILE) $(HEADERS_B) $(OBJS_B)
	@$(CC) $(CFLAGS_B) $(OBJS_B) -o $(BONUS) $(LIBFT_FLAGS) $(MLX_FLAGS)

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

.PHONY: all clean fclean re \
	bonus bonus_clean bonus_fclean \
	$(LIBFT) $(LIBFT)_clean $(LIBFT)_fclean \
	$(MLX) $(MLX)_clean
