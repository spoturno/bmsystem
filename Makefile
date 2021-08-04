all: main

.PHONY: all clean_bin clean_test clean testing

MODULOS = utils user userTable timer transactions

# directories
HDIR = include
CPPDIR = src
ODIR = obj

TESTDIR = tests

# extensions
EXT = cpp
# compilator
CC = g++ #gcc
LD = g++ # gcc


CFLAGS = -Wall -Werror -I$(HDIR) -g -DNDEBUG

HS = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.$(EXT))
OS = $(MODULOS:%=$(ODIR)/%.o)

MAIN = main
EXE = main

$(ODIR)/$(MAIN).o:$(MAIN).$(EXT) Makefile
	@printf 'Compilando $(<) \n'; \
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(CPPDIR)/%.$(EXT) $(HDIR)/%.h
	@printf 'Compilando $(<) \n'; \
	$(CC) $(CCFLAGS) -c $< -o $@ 


$(EXE):$(ODIR)/$(MAIN).o $(OS)
	@printf 'Compilando y enlazando $(@) \n'; \
	$(LD) $(CCFLAGS) $^ -o $@

clean_bin:
	@rm -f $(EXE) $(ODIR)/$(MAIN).o $(OS)

clean_test:
	@rm -f $(EXE) $(ODIR)/$(MAIN).o $(OS) $(LIB)

clean: clean_test clean_bin
	@rm -f *~ $(HDIR)/*~ $(CPPDIR)/*~ 
