#Deirectorys
BINDIR = $(CURDIR)/bin/

#Sources	
SRCS = $(wildcard *.cpp)

BINFILE = $(BINDIR)$(TARGET_NAME)

TARGET_NAME = main

#===============================
# Compiler configurations
#===============================

CC = g++

#===============================
# Build rules
#===============================

run: create_bin_dir $(SRCS)
	$(CC) -o $(BINFILE) $(SRCS)

create_bin_dir:
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)