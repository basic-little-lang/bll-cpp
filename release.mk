CC = g++
CCFLAGS = -c -Wall --std=c++11

LINKER = g++
LINKERFLAGS = -Wall --std=c++11 -o

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
