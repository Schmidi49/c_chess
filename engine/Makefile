#
# Compiler settings
#
BASE_DIR = ../
CC := C:\msys64\mingw64\bin\gcc.exe
CFLAGS := -Wall -Wextra -I$(BASE_DIR)

.PHONY: all clean debug prepdbg release preprel remake
all: release

#
# Project files
#
SRCDIR = source
#INCDIR = include
#DEPS = module.h
SRCS = main.c module.c
EXENAME  = runable

#
# Release build settings
#
RELDIR = release
RELEXE = $(RELDIR)/$(EXENAME)
RELOBJS = $(addprefix $(RELDIR)/, $(SRCS:.c=.o))
release: CFLAGS += -O3 -DNDEBUG

#
# Release rules
#
release: preprel $(RELEXE)
	@echo release target finished succesfully

preprel:
	@mkdir -p $(RELDIR)

$(RELEXE): $(RELOBJS)
	@echo
	@echo linking $(RELEXE)
	$(CC) $(CFLAGS) -o $(RELEXE) $^

$(RELDIR)/%.o: $(SRCDIR)/%.c
	@echo compiling $@
	$(CC) -c $(CFLAGS) -o $@ $<

#
# Debug build settings
#
DBGDIR = debug
DBGEXE = $(DBGDIR)/$(EXENAME)
DBGOBJS = $(addprefix $(DBGDIR)/, $(SRCS:.c=.o))
debug: CFLAGS += -ggdb3 -O0 -DDEBUG

#
# Debug rules
#
debug: prepdbg $(DBGEXE)
	@echo debug target finished succesfully

prepdbg:
	@mkdir -p $(DBGDIR)

$(DBGEXE): $(DBGOBJS)
	@echo
	@echo linking $(DBGEXE)
	$(CC) $(CFLAGS) -o $(DBGEXE) $^

$(DBGDIR)/%.o: $(SRCDIR)/%.c
	@echo compiling $@
	$(CC) -c $(CFLAGS) -o $@ $(SRCDIR)/$<

#
# Other rules
#
remake: clean all

clean:
	@echo cleaning all build dirs:
	rm -rf $(RELDIR) $(DBGDIR)
	@echo