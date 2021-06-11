target: parser

OBJS = main.o grammar.o lexical.o code_gen.o ast.o\

#LLVMCONFIG = /usr/bin/llvm-config
#CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
#LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic -L/usr/local/lib -ljsoncpp
#LIBS = `$(LLVMCONFIG) --libs`

.PHONY: target clean test 

code_gen.cpp: code_gen.h ast.h 

grammar.cpp: grammar.y
	bison -d -o grammar.cpp grammar.y 

grammar.hpp: grammar.cpp

lexical.cpp: lexical.l grammar.hpp
	flex -o lexical.cpp lexical.l 

%.o: %.cpp ast.h type.h code_gen.h
	g++ -c $(CPPFLAGS) -o $@ $<

parser: $(OBJS)
	g++ $(CPPFLAGS) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)


test: parser test_input
	cat test_input | ./parser

clean:
	$(RM) -rf $(OBJS) grammar.cpp grammar.hpp test parser lexical.cpp 

