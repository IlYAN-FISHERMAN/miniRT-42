# set GARBAGE_COLLECTOR to 1 to enable garbage collector
CFLAGS = -D GARBAGE_COLLECTOR=0

CC = gcc
CFLAGS += -Wall -Wextra -Werror -Ofast -march=native -mtune=native

FILES =	garbage_collector/ft_garbage_collector \
		garbage_collector/ft_garbage_utils \
		get_next_line/ft_get_next_line \
		linked_list/ft_lstadd \
		linked_list/ft_lstclear \
		linked_list/ft_lstgetters \
		linked_list/ft_lstiter \
		linked_list/ft_lstrotate \
		math/ft_equals \
		math/ft_minmaxabs \
		memory/ft_calloc \
		memory/ft_memcmp \
		memory/ft_memcpy \
		memory/ft_memset \
		memory/ft_memsuperclear \
		memory/ft_reallocf \
		memory/ft_swap \
		print/ft_print_utils \
		print/ft_print \
		print/ft_printf_utils \
		print/ft_printf \
		string/ft_atoi \
		string/ft_charis \
		string/ft_free_tab \
		string/ft_itoa \
		string/ft_split \
		string/ft_strchr \
		string/ft_strcmp \
		string/ft_strdup \
		string/ft_striteri \
		string/ft_strjoin \
		string/ft_strlcpy \
		string/ft_strlen \
		string/ft_strreplace \
		string/ft_strsepjoin \
		string/ft_substr \
		string/ft_tab \
		string/ft_touplo \

SECURED_FILES = $(FILES) garbage_collector/ft_garbage_galloc_secure
UNSECURED_FILES = $(FILES) garbage_collector/ft_garbage_galloc

CFILES = $(UNSECURED_FILES:%=src/%.c)
OFILES = $(UNSECURED_FILES:%=obj/%.o)

SECURED_CFILES = $(SECURED_FILES:%=src/%.c)
SECURED_OFILES = $(SECURED_FILES:%=obj/%.o)

NAME = betterft.a

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "\t🤖 Compiling $<...\r"
	@$(CC) $(CFLAGS) -c $< -o $@ -I includes
	@printf "\33[2K"

$(NAME): $(CFILES) $(OFILES)
	@printf "\t🤖 Compiling $(NAME)...\r"
	@ar -rc $(NAME) $(OFILES)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) (unsecured galloc) is compiled ✅"

clean:
	@rm -rf obj
	@echo "\t[INFO]\t[$(NAME)]\t$(words $(OFILES)) object files deleted 🗑️"

fclean: clean
	@rm -f $(NAME)
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) is fully deleted 🗑️"

re: fclean all

unsecure: $(NAME)

secure: $(SECURED_CFILES) $(SECURED_OFILES)
	@printf "\t🤖 Compiling $(NAME)...\r"
	@ar -rcs $(NAME) $(SECURED_OFILES)
	@printf "\33[2K"
	@echo "\t[INFO]\t[$(NAME)]\t$(NAME) (secured allocations) is compiled ✅"

.PHONY = all clean fclean re secure unsecure
