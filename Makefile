#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmonteco <vmonteco@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 13:47:44 by vmonteco          #+#    #+#              #
#    Updated: 2015/10/25 10:59:04 by vmonteco         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEBUG=no

LIBRARY=library
SRC_FT=test_atoi.c \
test_bzero.c \
test_isalnum.c \
test_isalpha.c \
test_isascii.c \
test_isdigit.c \
test_islower.c \
test_isprint.c \
test_isupper.c \
test_itoa.c \
test_memalloc.c \
test_memccpy.c \
test_memchr.c \
test_memcmp.c \
test_memcpy.c \
test_memdel.c \
test_memmove.c \
test_memset.c \
test_nullread.c \
test_putchar.c \
test_putchar_fd.c \
test_putendl.c \
test_putendl_fd.c \
test_putnbr.c \
test_putnbr_fd.c \
test_putpositive.c \
test_putpositive_fd.c \
test_putstr.c \
test_putstr_fd.c \
test_strcat.c \
test_strchr.c \
test_strclr.c \
test_strcmp.c \
test_strcpy.c \
test_strdel.c \
test_strdup.c \
test_strequ.c \
test_striter.c \
test_striteri.c \
test_strjoin.c \
test_strlcat.c \
test_strlen.c \
test_strmap.c \
test_strmapi.c \
test_strncat.c \
test_strncmp.c \
test_strncpy.c \
test_strnequ.c \
test_strnew.c \
test_strnstr.c \
test_strrchr.c \
test_strsplit.c \
test_strstr.c \
test_strsub.c \
test_strtrim.c \
test_tolower.c \
test_toupper.c \
test_absolute.c \
test_sign.c \
test_putnstr.c \
test_lstnew.c \
test_lstdelone.c \
test_lstdel.c \
test_lstadd.c \
test_lstiter.c \
test_lstmap.c \
test_itoa.c \
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
