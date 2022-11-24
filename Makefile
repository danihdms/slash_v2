.DEFAULT_GOAL: slash

COMPILER=gcc
OPTIONS=-std=gnu17 -Iinclude -Wall -Wextra -Wconversion -Wunreachable-code -g
LIBS=-lreadline
COMPILE=$(COMPILER) $(OPTIONS) $(LIBS)

SOURCE_FILES= src/cd.c src/main.c src/pwd.c src/shell.c src/split.c src/strings.c
OBJECT_FILES=$(patsubst src/%.c,build/%.o,$(SOURCE_FILES))

slash: build/slash
	@mv build/slash .

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "help   Show this help message"
	@echo "build  Build the project"
	@echo "clean  Remove all build files"

clean:
	@rm -rf build
	@rm -f slash
	@echo "Cleaned build files"

build/%.o: src/%.c
	mkdir -p build
	$(COMPILE) -c $< -o $@

build/slash: $(OBJECT_FILES)
	$(COMPILE) -o build/slash $(OBJECT_FILES)

build: build/slash
	@printf "\033[32mYou can now run ./build/slash\n\033[0m"

all: build

sync-with-lulu:
	rsync -avz --delete --exclude '.git' --exclude 'build' . 'lulu:~/Slash'

jalon-1:
	./tests/jalon-1.sh
