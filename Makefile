CC = gcc
CFLAGS = -std=c99
SRCDIR = src
BINDIR = bin
TESTDIR = tests

SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(SOURCES:$(SRCDIR)/%.c=$(BINDIR)/%.o)
EXECUTABLE = squirrel

TESTSOURCES := $(wildcard $(TESTDIR)/test_*.c)
TESTOBJECTS := $(TESTSOURCES:$(TESTDIR)/%.c=$(BINDIR)/%.o)
TESTEXECUTABLE = test_runner

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(BINDIR)/$@

$(OBJECTS): $(BINDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

test: $(TESTEXECUTABLE)
	./$(BINDIR)/$(TESTEXECUTABLE)

$(TESTEXECUTABLE): $(TESTOBJECTS) $(filter-out $(BINDIR)/main.o, $(OBJECTS))
	$(CC) $^ -o $(BINDIR)/$@

$(TESTOBJECTS): $(BINDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(BINDIR)/*

.PHONY: all clean test