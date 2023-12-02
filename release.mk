CC = g++
CCFLAGS = -c -Wall

LINKER = g++
LINKERFLAGS = -Wall -o

PROG = target

SRCDIR = src
BINARYDIR = bin

OBJS = $(patsubst $(SRCDIR)/%.cpp, $(BINARYDIR)/%.o, $(wildcard $(SRCDIR)/*.cpp))

$(BINARYDIR):
	mkdir $(BINARYDIR)

$(PROG): $(OBJS)
	$(LINKER) $(OBJS) $(LINKERFLAGS) $(PROG)

$(BINARYDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CCFLAGS) $< -o $@

all: $(BINARYDIR) $(PROG)

clean:
	rm -rf *.o $(PROG) $(BINARYDIR)

.PHONY: all clean
.DEFAULT_GOAL = all
