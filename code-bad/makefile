proj5: proj5Main.o proj5Tokens.o proj5Stack.o
	g++ -o proj5 proj5Main.o proj5Tokens.o proj5Stack.o

proj5Main.o: proj5Main.cpp proj5Tokens.h
	g++ -c proj5Main.cpp

proj5Tokens.o: proj5Tokens.cpp proj5Tokens.h
	g++ -c proj5Tokens.cpp

proj5Stack.o: proj5Stack.cpp proj5Stack.h
	g++ -c proj5Stack.cpp

clean:
	rm proj5 proj5Main.o proj5Tokens.o proj5Stack.o
