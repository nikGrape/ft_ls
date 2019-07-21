# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinograd <vinograd@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/20 19:18:00 by vinograd          #+#    #+#              #
#    Updated: 2019/07/20 19:37:36 by vinograd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls

SRCS=src/*.c

INCLUDES=libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft/ re
	gcc -Wall -Wextra -Werror $(SRCS) $(INCLUDES) -o $(NAME)

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
