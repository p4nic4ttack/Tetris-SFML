# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall -Wextra

# Libraries
LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRCS := $(wildcard *.cpp)

# Header files (if needed)
HDRS := $(wildcard *.h)

# Output executable
OUTPUT := Tetris

# Build rule
$(OUTPUT): $(SRCS) $(HDRS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(OUTPUT) $(LIBS)

# Clean rule
clean:
	rm -f $(OUTPUT)

# Phony target to prevent conflicts with files named 'clean'
.PHONY: clean
