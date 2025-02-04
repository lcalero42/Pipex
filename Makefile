CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c libft/ft_strdup.c libft/ft_strjoin.c \
	libft/ft_strlen.c srcs/parse_commands.c libft/ft_bzero.c \
	srcs/exec.c libft/ft_split.c libft/ft_calloc.c \
	libft/ft_strlcat.c srcs/free_data.c
HEADERS = includes/pipex.h

OBJS_DIR = objects/
OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = pipex

all: $(LIBFT) $(NAME)

$(NAME) : $(OBJS)
	@echo "Linking $(NAME)..."
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(OBJS)

$(OBJS_DIR)%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_DIR)/libft.h
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -f $(LIBFT)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: re fclean clean all