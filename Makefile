# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/13 12:11:17 by asydykna          #+#    #+#              #
#    Updated: 2021/09/22 15:30:37 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = pipex.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c error_mngmt.c\
	ft_bzero.c ft_calloc.c ft_memset.c ft_split.c ft_strncmp.c utils.c \
	ft_strjoin.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c checks.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

vpath %.c src

vpath %.h include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	norminette

.SILENT: $(OBJ)

.PHONY: all clean fclean re norm