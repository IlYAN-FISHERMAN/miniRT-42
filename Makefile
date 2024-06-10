CC = gcc

CFLAGS = -Wall -Werror -Wextra -Ofast

OS =

MINILIBX_MACOS_PATH = libs/minilibx_opengl/
MINILIBX_LINUX_PATH = libs/minilibx-linux/
MINILIBX_LIB = libmlx.a
MINILIBX_PATH =

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CFLAGS += -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
	MINILIBX_PATH = $(MINILIBX_LINUX_PATH)
	OS = linux
endif

ifeq ($(UNAME_S),Darwin)
	CFLAGS += -framework OpenGL -framework AppKit
	MINILIBX_PATH = $(MINILIBX_MACOS_PATH)
	OS = macos
endif

RM = rm -rf

NAME = miniRT

LIBFT_PATH = ./libs/betterft/
FILES_PATH = ./src/

MINILIBX_LIB := $(MINILIBX_PATH:%=%$(MINILIBX_LIB))
LIBFT_LIB = $(LIBFT_PATH:%=%betterft.a)

FILES = $(FILES_PATH)miniRT

CFILES = $(FILES:%=%.c)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Nettoyage fichier residuels... ♻️ \n"
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MINILIBX_PATH) clean

fclean : clean
	@echo "\n [$(NAME)] - Supressions du reste... 🗑️\n"
	@rm -f $(NAME)

re :
	@make fclean
	@make all

debug : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFLAGS) $(CFILES) -g3 -fsanitize=address $(LIBFT_LIB) $(MINILIBX_LIB) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -o $(NAME)
	@echo " \t$(NAME) compiled ✅"

$(MINILIBX_LIB): $(MINILIBX_PATH)Makefile
	@make -C $(MINILIBX_PATH) all
	@printf "\33[2K"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

.PHONY : clean fclean all debug re
