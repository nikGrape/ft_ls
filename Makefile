# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/20 19:18:00 by vinograd          #+#    #+#              #
#    Updated: 2019/07/21 11:10:27 by Nik              ###   ########.fr        #
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
	/bin/rm $(NAME)

re: fclean all
