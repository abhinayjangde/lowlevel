.PHONY: build run

build:
	@gcc -o ./bin/main main.c

run: build
	@./bin/main