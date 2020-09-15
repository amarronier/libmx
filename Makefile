CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
SRC_FILES_NO_DIR = $(notdir $(SRC_FILES))
FILE_NAMES = $(SRC_FILES_NO_DIR:%.c=%)
LIB_NAME = libmx.a

all: install clean

install: LIBMX

LIBMX:
	@$(CC) $(CFLAGS) -c $(SRC_FILES) -I$(INC_DIR)
	@mkdir $(OBJ_DIR)
	@mv $(addsuffix ".o", $(FILE_NAMES)) $(OBJ_DIR)
	@ar rcs $(LIB_NAME) $(addprefix $(OBJ_DIR)/, $(addsuffix ".o", $(FILE_NAMES)))

uninstall: clean
	@rm -f $(LIB_NAME)

clean:
	@rm -rf $(OBJ_DIR)

reinstall: uninstall all
