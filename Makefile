#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 13:47:44 by vmonteco          #+#    #+#              #
#    Updated: 2015/10/23 16:08:45 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEBUG=no

LIBRARY=library
SRC_FT=ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_islower.c \
ft_isprint.c \
ft_isupper.c \
ft_itoa.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_nullread.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putpositive.c \
ft_putpositive_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_absolute.c \
ft_sign.c \
ft_putnstr.c \
ft_lstnew.c \
ft_lstdelone.c \
ft_lstdel.c \
ft_lstadd.c \
ft_lstiter.c \
ft_lstmap.c \
ft_itoa.c \
get_next_line.c

DIR_FT=./src/
LIST_FT=$(addprefix $(DIR_FT),$(SRC_FT))
O_FT=$(subst .c,.o,$(SRC_FT))
LIB_FT=libft.a
H_DIR=./includes/
H_FT=libft.h

TEST=test
TEST_BIN=test_bin
DIR_TEST=./test/
SRC_TEST=TEST_putchar.c TEST_putnbr.c TEST_putstr.c TEST_strncpy.c\
TEST_putpositive.c TEST_isalpha.c TEST_isdigit.c TEST_isalnum.c\
TEST_isascii.c TEST_isprint.c TEST_bzero.c TEST_memccpy.c TEST_strncat.c\
 TEST_memcpy.c TEST_atoi.c TEST_strcpy.c TEST_strdup.c TEST_strstr.c\
TEST_memset.c TEST_strcmp.c TEST_memchr.c TEST_strlcat.c TEST_strrchr.c\
TEST_memcmp.c  TEST_memmove.c TEST_strcat.c TEST_strchr.c TEST_strnstr.c\
TEST_strncmp.c TEST_memalloc.c TEST_memdel.c TEST_strnew.c TEST_strdel.c\
TEST_strclr.c TEST_striter.c TEST_striteri.c TEST_strmap.c TEST_strmapi.c\
TEST_strequ.c TEST_strnequ.c

MAIN_TEST=TEST_main.c
LIST_TEST=$(addprefix $(DIR_TEST), $(SRC_TEST))
O_TEST=$(subst .c,.o,$(SRC_TEST))
LIB_TEST=libtest.a
H_TEST=libtest.h

LIB=$(subst lib,-l,$(subst .a,,$(LIB_FT) ))

ifeq ($(DEBUG), yes)
	NAME=$(TEST_BIN)
	RESULT=$(TEST)
	CLEAN=$(O_TEST) $(O_FT) $(LIB_TEST) $(LIB_FT)
else
	NAME=$(LIBRARY)
	RESULT=$(LIB_FT)
	CLEAN=$(O_FT)
endif

all : $(NAME)

$(NAME) : $(RESULT)

$(TEST_BIN) : $(DIR_FT)$(LIB_FT) $(LIB_TEST) $(DIR_TEST)$(MAIN_TEST)
	$(CC) $(CFLAGS)  $(DIR_TEST)$(MAIN_TEST) -o $(TEST_BIN) -I./ -I$(DIR_TEST) \
	-L./ $(subst lib,-l,$(subst .a,,$(LIB_FT) $(LIB_TEST)))

$(LIB_FT) : $(H_DIR)$(H_FT) $(LIST_FT) $(H_DIR)$(H_FT)
	@echo "\n-CONSTRUCTION OF LIBRARY : " $@ "."
	@echo "-Compilation of the library sources files."
	$(CC) $(CFLAGS) -c $(LIST_FT) -I$(H_DIR)
	@echo "-Construct the library with temporary files."
	ar rc $@ $(O_FT)
	@echo "-Indexing the library"
	ranlib $@
	@echo "-CONSTRUCTION OF LIBRARY " $@ " : ENDED.\n"

$(LIB_TEST) : $(DIR_TEST)$(H_TEST) $(H_FT) $(LIST_TEST)
	@echo "\n-CONSTRUCTION OF LIBRARY : " $@ "."
	@echo "-Compilation of the library sources files."
	$(CC) $(CFLAGS) -c $(LIST_TEST) -I./ -I$(DIR_TEST)
	@echo "-Construct the library with temporary file."
	ar rc $@ $(O_TEST)
	@echo "-Indexing the library."
	ranlib $@
	@echo "-CONSTRUCTION OF LIBRARY.\n" $@ " : ENDED.\n"

.PHONY :

clean :
	rm -f $(CLEAN)

fclean : clean
	rm -f $(RESULT)

re : fclean clean all
