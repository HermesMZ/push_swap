NAME = push_swap
CHK_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = objs
OBJS_CHECKER_DIR = objs/checker
INCLUDES_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	check_input.c \
	chunk.c \
	cost_target.c \
	cost_utils.c \
	cost.c \
	exec_moves.c \
	hard_sort.c \
	index.c \
	init.c \
	min_max.c \
	push_swap_p.c \
	push_swap_r.c \
	push_swap_rr.c \
	push_swap_s.c \
	push_swap.c \
	simple_math.c \
	sort_utils.c \
	utils.c \

CHECKER_SRCS = \
	check_input.c \
	checker_utils.c \
	checker.c \
	index.c \
	init.c \
	min_max.c \
	push_swap_p.c \
	push_swap_r.c \
	push_swap_rr.c \
	push_swap_s.c \
	sort_utils.c \
	utils.c \

SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS_PATH:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

SRCS_CHECKER_PATH = $(addprefix $(SRCS_DIR)/, $(CHECKER_SRCS))
OBJS_CHECKER = $(SRCS_CHECKER_PATH:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_DIR)/includes

all: $(LIBFT) $(NAME) checker

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Construction de libft.a..."
	@$(MAKE) -C $(LIBFT_DIR)

checker: $(OBJS_CHECKER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(LIBFT) -o $(CHK_NAME)

$(OBJS_CHECKER_DIR)/%.o: $(SRCS_CHECKER_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Nettoyage de $(NAME) et de libft..."
	@rm -f $(NAME)
	@rm -f $(CHK_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
