####################################################################################################
## Application Build Configuration
####################################################################################################
.POSIX:
.SUFFIXES:

## Compiler Selection
##
##   Prefer local configuration
##
CC  := clang  # C Compiler
CXX := clang++  # C++ Compiler

## Preprocessor Configuration
##
##   Custom configuration should come before $(CPPFLAGS) to prioritize local
##   configurations
##
override CPPFLAGS := $(CPPFLAGS)

## Compiler Configuration
##
##   Custom configuration should come before $(CFLAGS) and $(CXXFLAGS) to
##   prioritize local configurations
##
COMMON_CFLAGS := -Wall -Wextra -g

override CFLAGS   := $(COMMON_CFLAGS) $(CFLAGS)
override CXXFLAGS := $(COMMON_CFLAGS) -std=c++11 $(CXXFLAGS)

## Linker Configuration
##
##   Custom configuration should come before $(LDFLAGS) to prioritize local
##   configurations
##
override LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system $(LDFLAGS)

## Debugger Options
##
RELEASE_FLAGS := -DNDEBUG
DEBUG_FLAGS   := -DDEBUG

## Recursive Wildcards
##
##   This function acts similar to the $(wilcard) builtin, but can find files
##   recursively
##
##   $(call rwildcard,dir/,*.ext)
##
##   When using rwildcard the directory *must* have the trailing slash
##
rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

## Unique
##
unique = $(if $1,$(firstword $1) $(call unique,$(filter-out $(firstword $1),$1)))

####################################################################################################
## Application Configuration
####################################################################################################

EXE := game_main

SRC_DIR   := src
SRC_FILES := $(call rwildcard,$(SRC_DIR)/,*.cpp)

OBJ_DIR        := build/obj
OBJ_FILES      := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
OBJ_FILES_DIRS := $(call unique,$(dir $(OBJ_FILES)))

DEP_DIR        := build/dep
DEP_FILES      := $(patsubst $(SRC_DIR)/%.cpp,$(DEP_DIR)/%.d,$(SRC_FILES))
DEP_FILES_DIRS := $(call unique,$(dir $(DEP_FILES)))

####################################################################################################
## Application Setup
####################################################################################################

all: directories $(EXE)

-include $(DEP_FILES)

debug: export CPPFLAGS := $(DEBUG_FLAGS) $(CPPFLAGS)
release: export CPPFLAGS := $(RELEASE_FLAGS) $(CPPFLAGS)

debug: all
release: all

$(EXE): $(OBJ_FILES)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling: $< -> $@"
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -w -c -o $@ -MP -MMD -MF $(DEP_DIR)/$(notdir $@) $<

####################################################################################################
## Application Utilities
####################################################################################################

## Directory Creation
##
DIRECTORIES := 		\
	$(OBJ_FILES_DIRS)	\
	$(DEP_FILES_DIRS)

.PHONY: directories $(DIRECTORIES)
directories: $(DIRECTORIES)

$(DIRECTORIES):
	@mkdir -p $@

## Cleanup
##
.PHONY: clean
clean:
	@rm -f $(EXE)		\
		$(OBJ_FILES)	\
		$(DEP_FILES)

## Debug Printing
##
print-%:
	@echo $* = $($*)


















