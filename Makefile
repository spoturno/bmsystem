MODULOS = utils user userTable

# directories
HDIR = include
CPPDIR = src
ODIR = obj

TESTDIR = tests

# extensions
EXT = cpp
# compilator
CC = g++ #gcc -x c
LD = g++ #gcc


CFLAGS = -Wall -Werror -I$(HDIR) -g -DNDEBUG

HS = $(MODULOS:%=$(HDIR)/%.h)
CPPS = $(MODULOS:%=$(CPPDIR)/%.$(EXT))
OS = $(MODULOS:%=$(ODIR)/%.o)

MAIN = main
EXE = main

$(ODIR)/$(MAIN).o:$(MAIN).$(EXT) Makefile
	@printf 'Compiling $(<) \n'; \
	$(CC) $(CFLAGS) -c $< -o @

$(ODIR)/%.o: $(CPPDIR)/%.$(EXT) $(HDIR)/%.h
	@printf 'Compiling $(<) \n ;' \
	$(CC) $(CCFLAGS) -c $< -o $@ ; \


$(EXE):$(ODIR)/$(MAIN).o $(OS)
	@printf 'Compiling and linking $(@) \n ;' \
	$(LD) $(CCFLAGS) $^ -o $@


