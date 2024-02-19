# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daguilar <daguilar@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 17:54:29 by daguilar          #+#    #+#              #
#    Updated: 2024/02/19 16:32:45 by daguilar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH 		= includes/libft

SRCS = $(wildcard src/push_swap.c src/operations/*.c src/utils/*.c src/sort/*.c src/creation/*.c)

BONUS_SRCS	= $(wildcard src/push_swap.c src/bonus/checker.c src/operations/*.c src/utils/*.c src/sort/*.c src/creation/*.c)

OBJS			= $(SRCS:.c=.o)

OBJS_BONUS		= ${BONUS_SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap

BONUS_NAME 		= checker

all:			$(NAME)

bonus:			$(BONUS_NAME)

$(NAME):		$(LIBFT_PATH)/libft.a $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH)/libft.a

$(BONUS_NAME):	$(LIBFT_PATH)/libft.a $(OBJS_BONUS)
			$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJS_BONUS) $(LIBFT_PATH)/libft.a

$(LIBFT_PATH)/libft.a:
	@make -C $(LIBFT_PATH)

clean:
			$(RM) $(OBJS) $(LIBFT_PATH)/libft.a $(OBJS_BONUS)
			@make -C $(LIBFT_PATH) clean

fclean:			clean
			$(RM) $(NAME) $(LIBFT_PATH)/libft.a $(BONUS_NAME)
			@make -C $(LIBFT_PATH) fclean
			

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus