proj5: schen237Proj5.o proj5Tokens.o proj5Stack.o
	g++ -o proj5 schen237Proj5.o proj5Tokens.o proj5Stack.o

schen237Proj5.o: schen237Proj5.cpp proj5Tokens.h
	g++ -c schen237Proj5.cpp

proj5Tokens.o: proj5Tokens.cpp proj5Tokens.h
	g++ -c proj5Tokens.cpp

proj5Stack.o: proj5Stack.cpp proj5Stack.h
	g++ -c proj5Stack.cpp

clean:
	rm proj5 schen237Proj5.o proj5Tokens.o proj5Stack.o
