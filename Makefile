define HEADER
=======================================================================================================================

                   
      | |    _                            / _____)        _                 
       \ \  | |_    ____  _   _   ____   | /  ___   ____ | |_    ____   ___ 
        \ \ |  _)  / _  )| | | | / _  )  | | (___) / _  ||  _)  / _  ) /___)
    _____) )| |__ ( (/ /  \ V / ( (/ /   | \____/|( ( | || |__ ( (/ / |___ |
   (______/  \___) \____)  \_/   \____)   \_____/  \_||_| \___) \____)(___/ 

    ______   _  _  _      _____         _   
   (____  \ (_)| || |    (_   _)       | |       
    ____)  ) _ | || |      | |    ___  | | _    ___ 
   |  __  ( | || || |      | |   / _ \ | || \  /___)
   | |__)  )| || || |   ___| |  | |_| || |_) )|___ |
   |______/ |_||_||_|  (____/    \___/ |____/ (___/ 
⠀⠀⠀⠀⠀⠀⠀⠀⠀
           
=======================================================================================================================
endef
export HEADER

define LIB_HEADER

                            __ __ __                  __ __ __                     __              
.----.-----.--------.-----.|__|  |__|.-----.-----.   |  |__|  |--.----.---.-.----.|__|.-----.-----.
|  __|  _  |        |  _  ||  |  |  ||     |  _  |   |  |  |  _  |   _|  _  |   _||  ||  -__|__ --|
|____|_____|__|__|__|   __||__|__|__||__|__|___  |   |__|__|_____|__| |___._|__|  |__||_____|_____|
                    |__|                   |_____|                                                 

endef
export LIB_HEADER

define APP_HEADER

                            __ __ __                             __         __ ______ _______       _____  ______ 
.----.-----.--------.-----.|__|  |__|.-----.-----.    .--------.|__|.-----.|__|   __ \_     _|_____|  |  ||__    |
|  __|  _  |        |  _  ||  |  |  ||     |  _  |    |        ||  ||     ||  |      < |   ||______|__    |    __|
|____|_____|__|__|__|   __||__|__|__||__|__|___  |    |__|__|__||__||__|__||__|___|__| |___|          |__||______|
                    |__|                   |_____|                                                                

endef
export APP_HEADER

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I libs/betterft/includes/ -lm -Ofast -march=native -mtune=native

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
LIBFT_LIB = $(LIBFT_PATH:%=%betterft.a)
LIBFT_BUILD = unsecure
FILES_PATH = ./src/

MINILIBX_LIB := $(MINILIBX_PATH:%=%$(MINILIBX_LIB))

FILES =	$(FILES_PATH)main \
		$(FILES_PATH)camera/camera \
		$(FILES_PATH)camera/camera_utils \
		$(FILES_PATH)camera/image \
		$(FILES_PATH)camera/render_utils \
		$(FILES_PATH)exit_handler/exit_handler_$(OS) \
		$(FILES_PATH)exit_handler/exit_handler_utils \
		$(FILES_PATH)matrix/matrix3 \
		$(FILES_PATH)matrix/matrix4_utils \
		$(FILES_PATH)matrix/matrix4 \
		$(FILES_PATH)matrix/transformations \
		$(FILES_PATH)matrix/transformations_utils \
		$(FILES_PATH)objects/bumpmap \
		$(FILES_PATH)objects/bumpmap_utils \
		$(FILES_PATH)objects/cone \
		$(FILES_PATH)objects/cone_utils \
		$(FILES_PATH)objects/cylinder \
		$(FILES_PATH)objects/light \
		$(FILES_PATH)objects/objects \
		$(FILES_PATH)objects/patterns \
		$(FILES_PATH)objects/sphere \
		$(FILES_PATH)objects/material \
		$(FILES_PATH)objects/material2 \
		$(FILES_PATH)objects/plane \
		$(FILES_PATH)rays/intersection_utils \
		$(FILES_PATH)rays/intersection \
		$(FILES_PATH)rays/rays \
		$(FILES_PATH)vectors/vectors_instance \
		$(FILES_PATH)vectors/vectors_operations \
		$(FILES_PATH)vectors/vectors_products \
		$(FILES_PATH)vectors/vectors_properties \
		$(FILES_PATH)vectors/vectors_utils \
		$(FILES_PATH)world/world \
		$(FILES_PATH)color/color \
		$(FILES_PATH)color/color_operations \
		$(FILES_PATH)compute/compute \
		$(FILES_PATH)compute/lightning \
		$(FILES_PATH)compute/refractions \
		$(FILES_PATH)compute/shadow \
		$(FILES_PATH)generator/rt_generator \
		$(FILES_PATH)generator/rt_generate_nbr \
		$(FILES_PATH)generator/rt_generate_scene \
		$(FILES_PATH)generator/rt_generator_obj \
		$(FILES_PATH)utils/ft_split_sp_tab \
		$(FILES_PATH)utils/ft_strlen_tab \
		$(FILES_PATH)utils/help_message \
		$(FILES_PATH)utils/ft_atof \
		$(FILES_PATH)miniRT \
		$(FILES_PATH)parsing/parsing \
		$(FILES_PATH)parsing/error_handling \
		$(FILES_PATH)parsing/get_amb \
		$(FILES_PATH)parsing/get_cam \
		$(FILES_PATH)parsing/get_obj \
		$(FILES_PATH)parsing/get_size \
		$(FILES_PATH)parsing/obj_cy \
		$(FILES_PATH)parsing/obj_co \
		$(FILES_PATH)parsing/obj_lig \
		$(FILES_PATH)parsing/obj_pl \
		$(FILES_PATH)parsing/obj_sp \
		$(FILES_PATH)parsing/only_function \
		$(FILES_PATH)parsing/check_range_format \
		$(FILES_PATH)parsing/get_define \
		$(FILES_PATH)parsing/get_mat \
		$(FILES_PATH)parsing/print_token

FILES_NON_BONUS =	$(FILES) \
					$(FILES_PATH)camera/render \

FILES_BONUS =	$(FILES) \
				$(FILES_PATH)camera/render_fast_thread \
				$(FILES_PATH)camera/render_thread \
				$(FILES_PATH)camera/thread_utils \

CFILES = $(FILES_NON_BONUS:%=%.c)
CFILES_BONUS = $(FILES_BONUS:%=%.c)

all : $(NAME)

$(CFILES): header

clean :
	@echo "$$HEADER"
	@echo "\t[INFO]\t[$(NAME)]\tCleaning residual files... ♻️"
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@echo "\t[INFO]\t[$(NAME)]\tCleaning minilibx... ♻️"
	@$(MAKE) -C $(MINILIBX_PATH) clean --no-print-directory 1>/dev/null
	@echo "\t[INFO]\t[$(NAME)]\tMinilibx cleaned 🗑️"

fclean : clean
	@echo "\t[INFO]\t[$(NAME)]\tDeletions of the rest... 🗑️\n"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM

re :
	@make fclean
	@make all --no-print-directory

debug : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME) debug...\r"	
	@$(CC) $(CFILES) -g3 -fsanitize=address $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) compiled (debug) ✅\n"

debug_b : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME) debug...\r"	
	@$(CC) $(CFILES_BONUS) -g3 -fsanitize=address $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -D BONUS=1 -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) compiled (debug_b) ✅\n"

debug_g : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME) debug...\r"	
	@$(CC) $(CFILES) -g $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) compiled (debug_g) ✅\n"

debug_gb : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME) debug...\r"	
	@$(CC) $(CFILES_BONUS) -g $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D DEBUG=1 -D BONUS=1 -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) compiled (debug_gb) ✅\n"

$(NAME): $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME)...\r"
	@$(CC) $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) compiled ✅\n"

bonus : $(CFILES) $(LIBFT_LIB) $(MINILIBX_LIB)
	@echo "$$APP_HEADER"
	@printf "\t🤖 Compiling $(NAME) bonus...\r"
	@$(CC) $(CFILES_BONUS) $(LIBFT_LIB) $(MINILIBX_LIB) $(CFLAGS) -D BONUS=1 -o $(NAME)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) compiled with bonus ✅\n"

$(MINILIBX_LIB): $(MINILIBX_PATH)Makefile
	@echo "$$LIB_HEADER"
	@echo "\t🤖 Compiling $(MINILIBX_LIB)..."
	@make -C $(MINILIBX_PATH) all --no-print-directory 1>/dev/null
	@echo "\t[INFO]\t[$(MINILIBX_LIB)]\t$(MINILIBX_LIB) is compiled ✅"

$(LIBFT_LIB): $(LIBFT_PATH)Makefile
	@echo "$$LIB_HEADER"
	@make -C $(LIBFT_PATH) $(LIBFT_BUILD) --no-print-directory

header:
	@echo "$$HEADER"

.PHONY : clean fclean all debug debug_g bonus re debug_b debug_gb header
