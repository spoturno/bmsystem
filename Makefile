MODULOS = utils user userTable

# directories
HDIR	= include
CPPDIR	= src
ODIR	= obj

MAIN = main

# file extension
EXT = cpp

# compilation
CC=g++
CCFLAGS = -I$(HDIR)

$(ODIR)/$(MAIN).o:$(MAIN).$(EXT)
	$(CC) $(CCFLAGS) -c $< -o $@
