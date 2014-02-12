# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/09/25 08:56:14 by apergens          #+#    #+#              #
#    Updated: 2014/02/09 22:38:54 by apergens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc

NAME	= minitalk

LNAME	= ft ftprintf

DIR		= $(patsubst %,lib%,$(LNAME))

HDR		= $(patsubst %,%/%.a,$(DIR))

SRC		= ft_signal_init.c ft_signal_sleep.c ft_signal_write.c ft_ctob2.c \
		  ft_send.c ft_read.c ft_signal_handler.c ft_tail.c ft_check_client.c \
		  ft_putsignal.c ft_signal_only.c ft_signal_exit.c ft_exit.c

SERVER	= ft_minitalk_server.c $(SRC)
CLIENT	= ft_minitalk_client.c $(SRC)

LFLAGS	= $(patsubst %,-L%,$(DIR)) $(patsubst %,-l%,$(LNAME))

CFLAGS	= -Wall -Wextra -Werror -pedantic -I./includes -g

all: lib $(NAME)

$(NAME): server client

server: $(patsubst %.c,srcs/%.o,$(SERVER))
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

client: $(patsubst %.c,srcs/%.o,$(CLIENT))
	$(CC) $(CFLAGS) $(LFLAGS) -o $@ $^

lib:
	$(foreach var,$(DIR),make -C $(var);)

libclean:
	$(foreach var,$(DIR),make -C $(var) clean;)

binclean:
	rm -f $(patsubst %.c,srcs/%.o,$(SERVER)) $(patsubst %.c,srcs/%.o,$(CLIENT))

clean: libclean binclean

libfclean: libclean
	$(foreach var,$(DIR),make -C $(var) fclean;)

binfclean: binclean
	rm -f server client

fclean: libfclean binfclean

binre: binfclean $(name)

re: fclean all

.PHONY: all libclean binclean clean libfclean binfclean fclean binre re lib \
	server client
