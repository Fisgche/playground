#Deirectorys
BINDIR = $(CURDIR)/bin/

#Sources	
SRCS_TYPE = .cpp

NAME_SRC_CHECK_PERMUTATION = checkPermutation
SRC_CHECK_PERMUTATION = $(NAME_SRC_CHECK_PERMUTATION)$(SRCS_TYPE)

NAME_SRC_IS_UNIQUE = isUnique
SRC_IS_UNIQUE = $(NAME_SRC_IS_UNIQUE)$(SRCS_TYPE)

NAME_SRC_PALINDROME_PERMUTATION = palindromePermutation
SRC_PALINDROME_PERMUTATION  = $(NAME_SRC_PALINDROME_PERMUTATION)$(SRCS_TYPE)

BINFILE_CHECK_PERMUTATION = $(BINDIR)$(NAME_SRC_CHECK_PERMUTATION)
BINFILE_IS_UNIQUE = $(BINDIR)$(NAME_SRC_IS_UNIQUE)
BINFILE_PALINDROME_PERMUTATION  = $(BINDIR)$(NAME_SRC_PALINDROME_PERMUTATION)

#===============================
# Compiler configurations
#===============================

CC = g++

#===============================
# Build rules
#===============================

run: create_bin_dir compile_check_permutation compile_is_unique compile_palindrome_permutation

compile_check_permutation: $(SRC_CHECK_PERMUTATION)
	$(CC) -o $(BINFILE_CHECK_PERMUTATION) $(SRC_CHECK_PERMUTATION)

compile_is_unique: $(SRC_IS_UNIQUE)
	$(CC) -o $(BINFILE_IS_UNIQUE) $(SRC_IS_UNIQUE)

compile_palindrome_permutation: $(SRC_PALINDROME_PERMUTATION)
	$(CC) -o $(BINFILE_PALINDROME_PERMUTATION) $(SRC_PALINDROME_PERMUTATION)

create_bin_dir:
	mkdir -p $(BINDIR)

clean:
	rm -rf $(BINDIR)