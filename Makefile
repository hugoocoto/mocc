OUT = mocc

CC = clang
FLAGS = -Wall -Wextra -ggdb -nostdlib -static -Werror
INCL = -Imusl-1.2.6/include -Imusl-1.2.6/obj/include
LIBDIR = musl-1.2.6/lib
LIBS = $(LIBDIR)/crt1.o $(LIBDIR)/crti.o $(LIBDIR)/crtn.o -L$(LIBDIR) -Lmusl-1.2.6/arch/x86_64 -lc

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = obj
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
HEADERS_DIR = src
HEADERS = $(wildcard $(INC_DIR)/*.h))

all: $(OUT)

.PHONY: $(OUT)
$(OUT): $(OBJ)
	$(CC) $(FLAGS) $^ $(LIBS) $(LDFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCL) -c $^ -o $@

# Additional dependencies
$(OBJ_DIR)/%.o: $(HEADERS) Makefile

RM = rm -rf
clean:
	$(RM) $(OBJ_DIR)
