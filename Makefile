# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbifenzi <mbifenzi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 18:15:41 by mbifenzi          #+#    #+#              #
#    Updated: 2021/12/09 09:54:26 by mbifenzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	philo.c helper.c time.c execute.c

all :	$(NAME)

bonus : $(BONUS_NAME)
		
$(NAME): $(SRC)
		@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) #-fsanitize=address -g

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
