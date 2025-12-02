NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lreadline
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = minishell.c \
		utils.c \
		exec_cmdtree/exec_cmd.c \
		exec_cmdtree/exec_cmdtree.c \
		exec_cmdtree/exec_control.c \
		exec_cmdtree/exec_pipe.c \
		exec_cmdtree/redirect.c \
		exec_cmdtree/builtins/builtin_cd.c \
		exec_cmdtree/builtins/builtin_echo.c \
		exec_cmdtree/builtins/builtin_env.c \
		exec_cmdtree/builtins/builtin_exit.c \
		exec_cmdtree/builtins/builtin_export.c \
		exec_cmdtree/builtins/builtin_pwd.c \
		exec_cmdtree/builtins/builtin_unset.c \
		exec_cmdtree/builtins/builtin.c \
		exec_cmdtree/expand/expand.c \
		exec_cmdtree/expand/get_expanded_env.c \
		exec_cmdtree/expand/get_expanded_wild.c \
		exec_cmdtree/expand/Wildcards/filter_mode.c \
		exec_cmdtree/expand/Wildcards/helpers.c \
		exec_cmdtree/expand/Wildcards/modes.c \
		exec_cmdtree/expand/Wildcards/multi_wildcards.c \
		exec_cmdtree/expand/Wildcards/utils.c \
		get_cmdtree/get_cmdtree.c \
		get_cmdtree/here_doc.c \
		get_cmdtree/parse_line.c \
		get_cmdtree/read_and_accumulate_helpers.c \
		get_cmdtree/tokenize.c \
		get_cmdtree/check_syntax/operator_syntax.c \
		get_cmdtree/check_syntax/paren_syntax.c \
		get_cmdtree/check_syntax/redirection_syntax.c \
		get_cmdtree/check_syntax/syntax_checks.c \
		get_cmdtree/create_cmdtree/calc_and_split.c \
		get_cmdtree/create_cmdtree/create_cmdtree.c \
		get_cmdtree/create_cmdtree/paren_handler.c \
		get_cmdtree/create_cmdtree/tree_helpers.c \
		token_utils/fill_token_flags.c \
		token_utils/split_token.c \
		token_utils/token_utils_general.c \
		token_utils/get_argv_tokenlst.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)

bonus: all

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
