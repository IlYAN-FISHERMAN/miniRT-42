# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 21:08:55 by ilyanar           #+#    #+#              #
#    Updated: 2024/06/09 23:25:48 by ilyanar          ###   LAUSANNE.ch        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra -Ofast

MLXFLAGS = -framework OpenGL -framework AppKit

RM = rm -rf

NAME = miniRT

LIBFT_PATH = ./libs/betterft/
MLX_PATH = ./libs/minilibx/
FILES_PATH = ./src/

LIBFT_LIB = $(LIBFT_PATH:%=%betterft.a)
MLX = $(MLX_PATH:%=%libmlx.a)

FILES = $(FILES_PATH)miniRT

CFILES = $(FILES:%=%.c)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ \n"
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MLX_PATH) clean

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️\n"
	@rm -f $(NAME)

re :
	@make fclean
	@make all

debug : $(CFILES) $(LIBFT_LIB) $(MLX)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=address $(LIBFT_LIB) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB) $(MLX)
	@$(CC) $(CFLAGS) $(CFILES) $(LIBFT_LIB) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

$(MLX): $(MLX_PATH)Makefile
	@make -C $(MLX_PATH) all
	@printf "\33[2K"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

.PHONY : clean fclean all debug re
