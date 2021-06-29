
OBJS = grammar.o lexical.o code_gen.o ast.o main.o
CC = /usr/bin/clang++-12
LLVM_AS = /usr/lib/llvm-12/bin/llvm-as 
LLI = /usr/lib/llvm-12/bin/lli

LLVM_INCLUDE = -I /usr/lib/llvm-12/include
LLVM_LIBS = -L /usr/lib/llvm-12/lib
LD_FLAGS = -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib -ljsoncpp

.PHONY: build clean test

build:
	flex -o lexical.cpp lexical.l
	bison -d -o grammar.cpp grammar.y
	$(CC) -g $(LLVM_INCLUDE) $(LLVM_LIBS) $(LD_FLAGS) -lLLVM ./*.cpp -o parse

test:
# Q1: quicksort
	@echo "\n\n******Q1: Quicksort******"
	cat ../test/test1/quicksort.cmm | ./parse > ../test/test1/test1.ll
	llvm-as ../test/test1/test1.ll -o ../test/test1/test1.bc	
	$(CC) ../test/test1/test1.bc -o ../test/test1/test1_exe
	../test/test1/linux-amd64 ../test/test1/test1_exe
# Q2: Matrix multiplication
	@echo "\n\n******Q2: Matrix Multiplication******"
	cat ../test/test2/matrix.cmm | ./parse > ../test/test2/test2.ll
	llvm-as ../test/test2/test2.ll -o ../test/test2/test2.bc	
	$(CC) ../test/test2/test2.bc -o ../test/test2/test2_exe
	../test/test2/linux-amd64 ../test/test2/test2_exe
# Q3: Auto-Advaisor
	@echo "\n\n******Q3: Auto-Advisor******"
	cat ../test/test3/advisor.cmm | ./parse > ../test/test3/test3.ll
	llvm-as ../test/test3/test3.ll -o ../test/test3/test3.bc	
	$(CC) ../test/test3/test3.bc -o ../test/test3/test3_exe
	../test/test3/linux-amd64 ../test/test3/test3_exe

temp_test:
	cat ../test/test0.c | ./parse > ../test/test0.ll
	llvm-as ../test/test0.ll -o ../test/test0.bc
	$(CC) ../test/test0.bc -o ../test/test0_exe

clean:
	$(RM) -rf $(OBJS) grammar.cpp grammar.hpp parse lexical.cpp 
	$(RM) -f ../test/*.ll ../test/*.bc ../test/test0/test0_exe ../test/test1/test1_exe ../test/test2/test2_exe ../test/test3/test3_exe
	$(RM) -f ../test/test1/*.bc ../test/test1/*.ll ../test/test2/*.bc ../test/test2/*.ll ../test/test3/*.bc ../test/test3/*.ll 