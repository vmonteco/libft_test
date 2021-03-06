#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/16 14:33:54 by vmonteco          #+#    #+#              #
#    Updated: 2015/12/17 12:04:54 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=test_libft

CC=gcc
CFLAGS=-Wall -Werror -Wextra
LIBFT_FLAGS=-L./ -lft
LIBFLAGS=-L./ -ltest -ltools -lft

MAIN=./main.c

# Test library variables
SRC_DIR=./src/
SRC_TEST=test_atoi.c \
	test_absolute.c \
	test_bzero.c \
	test_isalnum.c \
	test_isalpha.c \
	test_isascii.c \
	test_isdigit.c \
	test_islower.c \
	test_isprint.c \
	test_isupper.c \
	test_itoa.c \
	test_lstnew.c \
	test_lstadd.c \
	test_lstdelone.c \
	test_lstdel.c \
	test_lstmap.c \
	test_lstiter.c \
	test_memalloc.c \
	test_memdel.c \
	test_memcpy.c \
	test_memccpy.c \
	test_memchr.c \
	test_memcmp.c
LIST_TEST=$(addprefix $(SRC_DIR),$(SRC_TEST))
H_DIR=./includes/
O_LIST=$(subst .c,.o,$(LIST_TEST))
LIBTEST=libtest.a

# Libft variables.
LIBFT=libft.a
LIBFT_REPO=../libft
#LIBFT_REPO=https://github.com/vmonteco/libft.git
LIBFT_DIR=libft
LIBFT_H=get_next_line.h \
	libft.h

# Tools library variables
TOOLS_DIR=./tools/
SRC_TOOLS=log_char.c \
	log_lst.c \
	log_nbr.c \
	log_positive.c \
	log_str.c \
	log_str_endl.c
LIST_TOOLS=$(addprefix $(TOOLS_DIR),$(SRC_TOOLS))
H_DIR=./includes/
O_TOOLS_LIST=$(subst .c,.o,$(LIST_TOOLS))
LIBTOOLS=libtools.a

# Files to rm with a clean
CLEAN=$(O_LIST) \
	$(LIBFT) \
	$(LIBTEST) \
	$(LIBTOOLS) \
	$(O_TOOLS_LIST) \
	$(addprefix $(H_DIR),$(LIBFT_H))

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBTEST) $(LIBTOOLS)
	$(CC) $(CFLAGS) $(MAIN) -o $@ -I $(H_DIR) $(LIBFLAGS)


$(LIBTOOLS) : $(O_TOOLS_LIST)
	ar rc $@ $(O_TOOLS_LIST)
	ranlib $@

$(LIBTEST) : $(O_LIST) $(LIBFT)
	ar rc $@ $(O_LIST)
	ranlib $@

%.o : %.c
	$(CC) $(CFLAGS) -I $(H_DIR) -o $@ -c $<

$(LIBFT) :
	rm -rf $(LIBFT_DIR)
	git clone -b withoutsegv $(LIBFT_REPO) $(LIBFT_DIR)
	make -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$@ ./
	cp $(LIBFT_DIR)/includes/libft.h $(H_DIR)

.PHONY :

clean :
	rm -f $(CLEAN)
	rm -Rf $(LIBFT_DIR)

fclean : clean
	rm -f $(NAME)

re: fclean clean all

test: re
	./$(NAME)
