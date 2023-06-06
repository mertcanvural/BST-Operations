# Variables
COURSE    = cs240
SEMESTER  = spring2023
CP_NUMBER = 4
LASTNAME  = Vural
GITUSERID = mertcanvural
EXE 	  = main_cp4

#		  ../cs240-spring2023-cp4-mertcanvural
REPODIR = ../$(COURSE)-$(SEMESTER)-cp$(CP_NUMBER)-$(GITUSERID)
#		  CP4_Vural_mvural1_mertcanvural.tar
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

# compiler flags
FLAGS = -Wall -Wextra -g
# Wall   : Enables all compiler warnings
# Wextra : Enables some additional compiler warnings beyond what is included with -Wall
# g		 : Generates debug information in the executable file

# compiler
CC = g++
# defines the C++ compiler
BIN = bin
# the compiled binary executable will be placed in ./BIN
OBJ = obj
# the compiled object files will be placed in ./OBJ

all : $(BIN)/$(EXE)
# default target when make command is run with no argument

$(BIN)/$(EXE) : $(OBJ)/main.o $(OBJ)/BST.o
	$(CC) $(FLAGS) $(OBJ)/main.o $(OBJ)/BST.o -o $@

$(OBJ)/main.o : main.cpp BST.h
	$(CC) $(FLAGS) -c main.cpp -o $@

$(OBJ)/BST.o  : BST.cpp BST.h
	$(CC) $(FLAGS) -c BST.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz
