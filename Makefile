# Compiler name and flags
CC = gcc -Wall

# Directory where to put build artefacts
BDIR = ./build

# List of source files
SRCS = $(wildcard ./src/*.c)

# List of test source files
TST_SRCS = ./src/counter.c \
					$(wildcard ./test/src/*.c)

# The build target executable
cwc: $(SRCS)
	@mkdir -p $(BDIR)
	$(CC) -o $(BDIR)/$@ $^

# The build target executable
testSuite: $(TST_SRCS)
	@mkdir -p $(BDIR)
	$(CC) -o $(BDIR)/$@ $^

# Clean objects in the directory
clean:
	rm -rf ./build