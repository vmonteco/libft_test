#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/16 14:33:54 by vmonteco          #+#    #+#              #
#    Updated: 2015/11/16 17:54:14 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=test

CC=gcc
CFLAGS=-Wall -Werror -Wextra
LIBFT_FLAGS=-L./ -lft
LIBFLAGS=-L./ -lft -ltest

MAIN=./main.c

# Test library variables
SRC_DIR=./src/
SRC_TEST=test_atoi.c
LIST_TEST=$(addprefix $(SRC_DIR),$(SRC_TEST))
H_DIR=./includes/
O_LIST=$(subst .c,.o,$(LIST_TEST))
LIBTEST=libtest.a

# Libft variables.
LIBFT=libft.a
LIBFT_REPO=../../libft
LIBFT_DIR=libft
LIBFT_H=get_next_line.h \
	libft.h

# Files to rm with a clean
CLEAN=$(O_LIST) \
	$(LIBFT) \
	$(LIBTEST) \
	$(addprefix $(H_DIR),$(LIBFT_H))

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBTEST)
	$(CC) $(CFLAGS) -o $@ -I $(H_DIR) $(LIBFLAGS)

$(LIBTEST) : $(O_LIST) $(LIBFT)
	ar rc $@ $(O_LIST)
	ranlib $@

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(LIBFT) :
	git clone $(LIBFT_REPO) $(LIBFT_DIR)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$@ ./
	cp $(LIBFT_DIR)/includes/libft.h $(H_DIR)
	rm -Rf $(LIBFT_DIR)

.PHONY :

clean :
	rm -f $(CLEAN)

fclean : clean
	rm -f $(NAME)

re: fclean clean all
