# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aomman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 12:26:51 by aomman            #+#    #+#              #
#    Updated: 2022/09/09 19:03:15 by aomman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LDFLAGS="-L/Users/aomman/.brew/opt/readline/lib"
CPPFLAGS="-I/Users/aomman/.brew/opt/readline/include"

SRC = minishell.c ft_split.c minishell_utils.c  minishell_utils2.c minishell_utils3.c\
		read_command.c\
		./built-ins/ft_pwd.c ./built-ins/ft_exece_utils.c\
		./built-ins/ft_cd.c ./built-ins/ft_echo.c ./built-ins/ft_env.c ./built-ins/ft_exit.c\
		./built-ins/ft_export.c ./built-ins/ft_unset.c ./built-ins/normale_export.c\
		./built-ins/ft_normale_export2.c ./built-ins/built_utils.c 

NAME = minishell

all : ${NAME}

${NAME} : 
	gcc -Wall -Wextra -Werror -g -fsanitize=address ${SRC} -lreadline ${LDFLAGS} ${CPPFLAGS} -o ${NAME}
	@ echo "\n\033[1;32mMinishell...!\033[0m\n"

clean : 
	rm -f ${NAME}

fclean : clean
	@ echo "\n\033[1;31mMinishell removed Successfully!\033[0m\n"

re : fclean all
