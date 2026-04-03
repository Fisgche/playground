# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Find all .cpp files recursively
SRCS := $(shell find . -name "*.cpp")

# Map to .o files inside bin/
OBJS := $(SRCS:./%.cpp=bin/%.o)

# Default target
all: $(OBJS)

# Rule: compile .cpp → bin/.../.o
bin/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf bin