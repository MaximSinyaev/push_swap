#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolen <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 15:10:57 by aolen             #+#    #+#              #
#    Updated: 2019/09/21 17:32:55 by lcarmelo         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FUNCS = \
        handle_args \
        errors \
        list_operations \
        print_stacks \
        stack_push \
        stack_reverse_rotate \
        stack_rotate \
        stack_swap \
        stack_check \
        clean_memory \
        getopt

FUNCS_CHECKER = \
        checker \
        checker_output

FUNCS_PS = \
	push_swap \
	median_search \
    stacks_refresh \
    stack_sort_1 \
    stack_sort_2

NAME = push_swap
NAME_CHECKER = checker
SRC = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS)))
SRC_PS = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS_PS)))
SRC_CHECKER = $(addprefix $(SRC_PATH), $(addsuffix .c, $(FUNCS_CHECKER)))
OBJS = $(addprefix $(SRC_PATH), $(addsuffix .o, $(FUNCS)))
OBJS_PS = $(addprefix $(SRC_PATH), $(addsuffix .o, $(FUNCS_PS)))
OBJS_CHECKER = $(addprefix $(SRC_PATH), $(addsuffix .o, $(FUNCS_CHECKER)))
SRC_PATH = ./src/
INCLUDE_PATH = ./includes -I./ft_printf/includes
CFLAGS = -g -Wall -Wextra -Werror -I$(INCLUDE_PATH)
OPT = -ofast
LIBFT = ft_printf/libftprintf.a
LIBS = -L./ft_printf -lftprintf
RED = "\033[1;31m"
PURPLE = "\033[1;35m"
GREEN = "\033[1;32m"
NOCOLOR = "\033[0m"

all: $(NAME) $(NAME_CHECKER)

$(LIBFT):
	make -C ./ft_printf

$(OBJS): %.o: %.c
	gcc $(OPT) -c $(CFLAGS) $^ -o $@

$(OBJS_PS): %.o: %.c
	gcc $(OPT) -c $(CFLAGS) $^ -o $@

$(OBJS_CHECKER): %.o: %.c
	gcc $(OPT) -c $(CFLAGS) $^ -o $@

$(NAME): $(LIBFT) $(OBJS) $(OBJS_PS)
	gcc $(OPT) $(CFLAGS) $(LIBS) $(OBJS_PS) $(OBJS) -o $(NAME)
	@echo $(GREEN)">>>Sucess! $(NAME) installed"$(NOCOLOR)'\n'

$(NAME_CHECKER): $(LIBFT) $(OBJS) $(OBJS_CHECKER)
	gcc $(OPT) $(CFLAGS) $(LIBS) $(OBJS_CHECKER) $(OBJS) -o $(NAME_CHECKER)
	@echo $(GREEN)">>>Sucess! $(NAME_CHECKER) installed"$(NOCOLOR)'\n'

clean:
	@echo $(PURPLE)">>> Deleting object files.."$(NOCOLOR)
	rm -f $(OBJS) $(OBJS_CHECKER) $(OBJS_PS)
	@make -C ./ft_printf clean

fclean: clean
	@echo $(PURPLE)">>> Deleting $(NAME)..."$(NOCOLOR)
	rm -f $(LIBFT)
	rm -f $(NAME) $(NAME_CHECKER)
	@echo $(GREEN)">>> $(NAME) deleted"$(NOCOLOR)'\n'

re: fclean all
