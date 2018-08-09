
CC=gcc
CXX=g++

CFLAGS	=   -g -std=c++11

RM=rm

OBJS =	FilmDBTester.o Film.o FilmDatabase.o Menu.o FilmMenu.o MenuUtilities.o NotFoundException.o PrecondViolatedExcep.o

EXES =	Project1

all:	$(EXES)

Project1: $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^	

	
%.o:	%.cpp %.h %.hpp
	$(CXX) -c $(CFLAGS) $< -o $@
	
clean:
	rm *.exe *.o
