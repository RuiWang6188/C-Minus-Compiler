target: parser

.PHONY: build clean 

build:
	flex -o lexical.cpp lexical.l
	bison -d -o grammar.cpp grammar.y
	clang++ -g -lLLVM ./*.cpp -o parse

clean:
	$(RM) -rf $(OBJS) grammar.cpp grammar.hpp test parser lexical.cpp 