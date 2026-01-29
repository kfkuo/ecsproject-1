AR = ar 
CXX = g++
CXXFLAGS = -std=c++17 -fno-inline

SRC_DIR = src
OBJ_DIR = obj
TESTSRC_DIR = testsrc
TESTOBJ_DIR = testobj
TESTBIN_DIR = testbin
INC_DIR = include

SRC = $(SRC_DIR)/StringUtils.cpp
OBJ = $(OBJ_DIR)/StringUtils.o

TEST_SRC = $(TESTSRC_DIR)/StringUtilsTest.cpp
TEST_OBJ = $(TESTOBJ_DIR)/StringUtilsTest.o
TEST_TARGET = $(TESTBIN_DIR)/teststrutils

BREW_PREFIX := $(shell brew --prefix 2>/dev/null)
GTEST_INC = -I/opt/homebrew/opt/googletest/include
GTEST_LIB = -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -lpthread

INCLUDES = -I$(INC_DIR)

.PHONY: all clean runtests directories

all: directories $(TEST_TARGET)

directories:
	mkdir -p $(OBJ_DIR) $(TESTOBJ_DIR) $(TESTBIN_DIR)

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(TEST_OBJ): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(GTEST_INC) -c $< -o $@

$(TEST_TARGET): $(OBJ) $(TEST_OBJ)
	$(CXX) $(OBJ) $(TEST_OBJ) $(GTEST_LIB) -o $(TEST_TARGET)

runtests: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -rf $(OBJ_DIR) $(TESTOBJ_DIR) $(TESTBIN_DIR)