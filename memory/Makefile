CFLAGS = -std=c23 -Wall -Wextra -Werror -fexec-charset=UTF-8 -Wno-unused-parameter

SRCS = \
	".\src\*.c" \
	".\src\types\*.c" \
	".\src\utils\*.c"

BUILD = .\build

all:
	make -B memory

$(BUILD):
	mkdir -p $(BUILD)

memory:
	gcc $(CFLAGS) -pedantic $(SRCS) -o $(BUILD)\prog

run: memory
	BUILD\prog.exe