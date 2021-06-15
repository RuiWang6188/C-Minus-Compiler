OBJS = grammar.o lexical.o code_gen.o ast.o main.o
CC = /usr/bin/clang++-12

LLVM_INCLUDE = -I /usr/lib/llvm-12/include
LLVM_LIBS = -L /usr/lib/llvm-12/lib
LD_FLAGS = -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib -ljsoncpp

.PHONY: build clean test

build:
	flex -o lexical.cpp lexical.l
	bison -d -o grammar.cpp grammar.y
	$(CC) -g $(LLVM_INCLUDE) $(LLVM_LIBS) $(LD_FLAGS) -lLLVM ./*.cpp -o parse

test:
	cat ../test/test0.c | ./parse

clean:
	$(RM) -rf $(OBJS) grammar.cpp grammar.hpp parse lexical.cpp 