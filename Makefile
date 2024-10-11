CC = gcc

CFLAGS = -Wall -Wextra -Werror -lm

OS =

MINILIBX_MACOS_PATH = libs/minilibx_opengl/
MINILIBX_LINUX_PATH = libs/minilibx-linux/
MINILIBX_LIB = libmlx.a
MINILIBX_PATH =

UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	CFLAGS += -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lz
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

FILES =	$(FILES_PATH)main \
		$(FILES_PATH)miniRT \
		$(FILES_PATH)camera/camera \
		$(FILES_PATH)camera/image \
		$(FILES_PATH)exit_handler/exit_handler_$(OS) \
		$(FILES_PATH)lightning/lightning \
		$(FILES_PATH)matrix/matrix2 \
		$(FILES_PATH)matrix/matrix3 \
		$(FILES_PATH)matrix/matrix4_utils \
		$(FILES_PATH)matrix/matrix4 \
		$(FILES_PATH)matrix/transformations \
		$(FILES_PATH)objects/cylinder \
		$(FILES_PATH)objects/light \
		$(FILES_PATH)objects/objects \
		$(FILES_PATH)objects/sphere \
		$(FILES_PATH)objects/plane \
		$(FILES_PATH)rays/intersection_utils \
		$(FILES_PATH)rays/intersection \
		$(FILES_PATH)rays/rays \
		$(FILES_PATH)vectors/vectors_instance \
		$(FILES_PATH)vectors/vectors_operations \
		$(FILES_PATH)vectors/vectors_products \
		$(FILES_PATH)vectors/vectors_properties \
		$(FILES_PATH)vectors/vectors_utils \
		$(FILES_PATH)color/color \
		$(FILES_PATH)color/color_operations \
		$(FILES_PATH)generator/rt_generator \
		$(FILES_PATH)generator/rt_generate_nbr \
		$(FILES_PATH)generator/rt_generate_scene \
		$(FILES_PATH)generator/rt_generator_obj \
		$(FILES_PATH)utils/ft_split_sp_tab \
		$(FILES_PATH)utils/ft_strlen_tab \
		$(FILES_PATH)parsing/error_handling \
		$(FILES_PATH)utils/ft_atof \
		$(FILES_PATH)parsing/parsing \
		$(FILES_PATH)parsing/get_amb \
		$(FILES_PATH)parsing/get_cam \
		$(FILES_PATH)parsing/get_obj \
		$(FILES_PATH)parsing/get_size \
		$(FILES_PATH)parsing/obj_cy \
		$(FILES_PATH)parsing/obj_lig \
		$(FILES_PATH)parsing/obj_pl \
		$(FILES_PATH)parsing/obj_sp \
		$(FILES_PATH)parsing/only_function \
		$(FILES_PATH)parsing/check_range_format \
		$(FILES_PATH)parsing/print_token

CFILES = $(FILES:%=%.c)

FILES_TEST =	$(FILES_PATH)main_test \
		$(FILES_PATH)camera/camera \
		$(FILES_PATH)camera/image \
		$(FILES_PATH)exit_handler/exit_handler_$(OS) \
		$(FILES_PATH)lightning/lightning \
		$(FILES_PATH)matrix/matrix2 \
		$(FILES_PATH)matrix/matrix3 \
		$(FILES_PATH)matrix/matrix4_utils \
		$(FILES_PATH)matrix/matrix4 \
		$(FILES_PATH)matrix/transformations \
		$(FILES_PATH)objects/cylinder \
		$(FILES_PATH)objects/light \
		$(FILES_PATH)objects/objects \
		$(FILES_PATH)objects/sphere \
		$(FILES_PATH)objects/plane \
		$(FILES_PATH)rays/intersection_utils \
		$(FILES_PATH)rays/intersection \
		$(FILES_PATH)rays/rays \
		$(FILES_PATH)vectors/vectors_instance \
		$(FILES_PATH)vectors/vectors_operations \
		$(FILES_PATH)vectors/vectors_products \
		$(FILES_PATH)vectors/vectors_properties \
		$(FILES_PATH)vectors/vectors_utils \
		$(FILES_PATH)color/color \
		$(FILES_PATH)color/color_operations \
		$(FILES_PATH)generator/rt_generator \
		$(FILES_PATH)generator/rt_generate_nbr \
		$(FILES_PATH)generator/rt_generate_scene \
		$(FILES_PATH)generator/rt_generator_obj \
		$(FILES_PATH)utils/ft_split_sp_tab \
		$(FILES_PATH)utils/ft_strlen_tab \
		$(FILES_PATH)utils/ft_atof \
		$(FILES_PATH)miniRT \
		$(FILES_PATH)parsing/parsing \
		$(FILES_PATH)parsing/error_handling \
		$(FILES_PATH)parsing/get_amb \
		$(FILES_PATH)parsing/get_cam \
		$(FILES_PATH)parsing/get_obj \
		$(FILES_PATH)parsing/get_size \
		$(FILES_PATH)parsing/obj_cy \
		$(FILES_PATH)parsing/obj_lig \
		$(FILES_PATH)parsing/obj_pl \
		$(FILES_PATH)parsing/obj_sp \
		$(FILES_PATH)parsing/only_function \
		$(FILES_PATH)parsing/check_range_format \
		$(FILES_PATH)parsing/print_token

CFILES_TEST = $(FILES_TEST:%=%.c)

all : $(NAME)

clean :
	@echo "\n [$(NAME)] - Cleaning residual files... ♻️ \n"
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(MINILIBX_PATH) clean

fclean : clean
	@echo "\n [$(NAME)] - Deletions of the rest... 🗑️\n"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re :
	@make fclean
	@make all

test : $(CFILES_TEST) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES_TEST) $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -g -o $(NAME) -D BONUS=1 -D DEBUG=1 -I libs/betterft/includes/
	@echo " \t$(NAME) test compiled ✅"

debug : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) -g3 -fsanitize=address $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -o $(NAME) -I libs/betterft/includes/
	@echo " \t$(NAME) compiled (debug) ✅"

debug_b : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) -g3 -fsanitize=address $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -D BONUS=1 -o $(NAME) -I libs/betterft/includes/
	@echo " \t$(NAME) compiled (debug_b) ✅"

debug_g : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) -g $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -o $(NAME) -I libs/betterft/includes/
	@echo " \t$(NAME) compiled (debug_g) ✅"

debug_gb : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) -g $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -D BONUS=1 -o $(NAME) -I libs/betterft/includes/
	@echo " \t$(NAME) compiled (debug_gb) ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\33[2K"

$(NAME): $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -o $(NAME) -I libs/betterft/includes/
	@echo " \t$(NAME) compiled ✅"

bonus : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@$(CC) $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D BONUS=1 -o $(NAME) -I libs/betterft/includes/
	@echo " \t$(NAME) compiled with bonus ✅"


$(MINILIBX_LIB): $(MINILIBX_PATH)Makefile
	@make -C $(MINILIBX_PATH) all
	@printf "\33[2K"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@make -C $(LIBFT_PATH) all

.PHONY : clean fclean all debug debug_g bonus re
