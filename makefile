# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  CFLAGS  = -g -Wall

  all: menus.o register.o login.o main.o main
 
  main: login.o menus.o register.o main.o
	$(CC) $(CFLAGS) -o main main.o login.o menus.o register.o
  

  menus.o: menus.h menus.cpp 
	$(CC) $(CFLAGS) -c menus.cpp

  register.o: register.h register.cpp 
	$(CC) $(CFLAGS) -c register.cpp
  
  login.o: login.h login.cpp 
	$(CC) $(CFLAGS) -c login.cpp
  
 
  main.o: register.h login.h menus.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

  clean:
	rm *.o main