# ECS34 Project 1

## Description
The basis of this project is to implement a set of string utilities in C++ with the use of Google Test, such as 
- Slice
- Capitalize
- Upper
- Lower
- LStrip
- RStrip
- Strip
- Center
- LJust
- RJust
- Replace
- Split
- Join
- ExpandTabs
- EditDistance

## Workflow
1. Create a git repositoty and add the provided files
I began the project by following the recommended approach, starting off with creating a git repository. This project was my first time being exposed to GitHub, so navigating that was an experience. However, I did do my coding on VSCode. 
2. Create a Makefile
We did some of the Makefile in class. I do have to admit that in class I was pretty confused because the speed of the class is quicker than my learning pace. However, with the use of ChatGPT, I asked it what each command means and does for greater understanding. The prompt that I used to ask ChatGPT is below. 
3. Write tests for each of the functions. 
I built off of what we had already written in class during discussion. However, in disussion, we used the word "Hello", but on my own I used the word "Tangerine" just for fun because I wanted to experiment and try new things. This part was difficult for me because for a lot of the commands, I did not remember how to write these functions, so I utilized Google Images and did Google searches to jog up my memory. After doing so, I wrote these down on my coding notebook by hand so I could really get it stuck in my mind.
4. Write the functions. 
I used the information we have learned in class about std::string to write these functions. This part too me the LONGEST time because even though it was only last quarter that I learned C for the first time, I don't think it was in my mind long enough that I was able to really apply my knowledge in this way, much less to a different coding language, especially since we . I am still adjusting and haven't been spending enough time studying for this class, so it really was a struggle. I asked my older sister and her boyfriend for help on this part, as they are both software engineers and utilize C++ regularly. However, they made sure that I would understand the material by making me write it down in my coding notebook. In addition to this, I had no clue what Google Tests were and so this was a very different experience in learning how to link it to my code. I learned THE MOST in this section, such as how to utilize #include <sstream>, #include <vector>, std::toupper, str.substr(start, end - start), std::string::npos, and so much more that my sister's boyfriend had taught me. Overall, I did have a difficult time with this project, but that is on my end, and I do need to work harder in this class. 
5. Checking code
I used Generative AI to check my code in the end, clean it up, and double check to make sure it was answering the prompt correctly. 

## Use of Generative AI
I did use ChatGPT but for the purpose of understanding the material that was given. To be honest, I really did struggle with this project, and because of conflict in scheduling, I didn't not utilize office hours, when I should have. So as a result, I used ChatGPT to help me, in which I have listed the prompts down below. I am also linking the ChatGPT chat so the professor is able to observe the responses that ChatGPT sent, instead of it all being listed here, as there was actually quite a bit. In the future, it will definitely be a lot shorter as I will be utilizing office hours and ask more questions. 

LINK TO CHAT: https://chatgpt.com/share/696f054c-5178-8009-bd66-1d35a54692fb

PROMPTS
1. what do each of these commands mean in C++?

AR = ar //archiver
CC = gcc //
CXX = g++


INC_DIR = ./include
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
TESTSRC_DIR = ./testsrc
TESTOBJ_DIR = ./testobj
TESTBIN_DIR = ./testbin
TESTCOVER_DIR = ./htmlcov

DEFINES += -I $(INC_DIR)
CFLAGS +=
CPPFLAGS += -std=c++17
LDFLAGS = 

TEST_CFLAGS = $(CFLAGS) -O0 -g --coverage
TEST_CPPFLAGS = $(CPPFLAGS) -fno-inline
TEST_LDFLAGS = $(LDFLAGS) -lgtest -lgtest_main -lpthread

TEST_OBJ_FILES = $(TESTSRC_DIR)/StringUtilsTest.o $(OBJ_DIR)/StringUtils.o

TEST_TARGET = $(TESTBIN_DIR)/teststrutils

all: directories

runtests: $(TEST_TARGETS)
	$(TEST_TARGET)
	lcov --capture --directory . --output-file $(TESTCOVER_DIR)/coverage.info --ignore-errors 
inconsistent,source
lcov --remove $(TESTCOVER_DIR)/coverage.info ‘/usr/*’ ‘*/testsrc/*’ --output-file 
$(TESTCOVER_DIR)/coverage.info
genhtml $(TESTCOVER_DIR)/coverage.info --output-directory $(TESTCOVER_DIR)

$(TEST_TARGET): $(TEST_OBJ_FILES) //left of colon is what you want to do
	$(CXX) $(TEST_CFLAGS) $(TEST_CPPFLAGS) $(TEST_OBJ_FILES) $(TEST_LDFLAGS) 
-o $(TEST_TARGET)

$(TESTOBJ_DIR)/StringUtilsTest.o: $(TESTSRC_DIR)/StringUtilsTest.cpp
	$(CXX) $(TEST_CFLAGS) $(TEST_CPPFLAGS) $(DEFINES) $(INCLUDE) -c 
$(TESTOBJ_DIR)/StringUtilsTest.cpp -o

$(TESTOBJ_DIR)/StringUtils.o: $(TESTSRC_DIR)/StringUtilsTest.cpp
	$(CXX) $(TEST_CFLAGS) $(TEST_CPPFLAGS) $(DEFINES) $(INCLUDE) -c 
$(TESTOBJ_DIR)/StringUtils.cpp -o

.PHONY: directories
directories: 
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(LIB_DIR)
	mkdir -p $(TESTBIN_DIR)
	mkdir -p $(TESTOBJ_DIR)
	mkdir -p $(TESTCOVER_DIR)

clean::
directories: 
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(TESTBIN_DIR)
	rm -rf $(TESTOBJ_DIR)
	rm -rf $(TESTCOVER_DIR)

.PHONY: clean

2. how to rewrite this Makefile so it is cleaner
3. can you make it make it compatible with GoogleTest for macOS
4. why is it compatible with google test?
5. in which occasions would one need a helper function in their code?
6. can you teach me how to write a custom google test helper function to compare two vectors of strings and make the test fail if their sizes or elements differ
7. what is GoogleTest for macOS, what does it do
8. what is BREW_PREFIX
9. what is GTEST_INC
10. what does $(shell brew --prefix 2>/dev/null) mean
11. what does .PHONY mean
12. what does $@ mean
13. how to write a test in GoogleTest but for slicing to imitate python, what is the format it should be
14. what does noexcept{ mean
15. what is the significance in stating namespace StringUtils{
16. what is LStrip
17. what does it look like in python
18. what is the difference between LStrip, RStrip, and Strip
19. is writing: 

std::string Center(const std::string &str) noexcept { 
    int width; 
    char fill; 
    int diff = width - str.size(); 
        
        if (diff <= 0) { 
            return str; 
        } 
        
        if (diff == 1) {
            return str + fill; 
        } 
        // diff >= 2 
        return std::string(1, fill) + str + std::string(1, fill); 
    } 
        
    the same as: 
    
    std::string Center(const std::string &str, int width, char fill) noexcept {
         int diff = width - str.size();
        if (diff <= 0) {
            return str; 
        } 
        
        if (diff == 1) {
            return str + fill;
        } 
        
        // diff >= 2 
        return std::string(1, fill) + str + std::string(1, fill); 
    }
20. what does bool ignorecase mean
21. why is my code not working, can you check it

#include "StringUtils.h"
#include <cctype>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

namespace StringUtils {

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {
    ssize_t len = str.size();
    if (start < 0) start += len;
    if (end <= 0) end += len;
    if (start < 0) start = 0;
    if (end > len) end = len;
    if (start >= end) return "";
    return str.substr(start, end - start) // <-- missing semicolon
}

std::string Capitalize(const std::string &str) noexcept {
    if (str.empty()) return "";
    std::string result = str;
    result[0] = std::toupper(result[0]);
    std::transform(result.begin() + 1, result.end(), result.begin() + 1, ::tolower);
    return result;
}

std::string Upper(const std::string &str) noexcept {
    std::string result = str;
    std::transfom(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

std::string Lower(const std::string &str) noexcept {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

std::string LStrip(const std::string &str) noexcept {
    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == std::string::npos) return "";
    return str.substr(start);
}

std::string RStrip(const std::string &str) noexcept {
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    if (end == std::string::npos) return "";
    return str.substr(0, end + 1);
}

std::string Strip(const std::string &str) noexcept {
    return LStrip(RStripr(str));
}

std::string Center(const std::string &str, int width, char fill) noexcept {
    int diff = width - str.size();

    if (diff <= 0) {
        return str;
    }

    if (diff == 1) {
        return str + fill;
    }

    return std::string(1, fill) + str + std::string(1, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept {
    int pad = width - str.size() - 1;
    if (pad <= 0) return str;
    return str + std::string(pad, fill);
}

std::string RJust(const std::string &str, int width, char fill) noexcept {
    int pad = width - str.size() - 1;
    if (pad <= 0) return str;
    return std::string(pad, fill) + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept {
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), rep);
        pos += rep.length();
    }
    return result;
}

std::vector<std::string> Split(const std::string &str, const std::string &splt) noexcept {
    std::vector<std::string> result;
    if (splt.empty()) {
        std::istringstream iss(str);
        std::string token;
        while (iss >> token) result.push_back(token);
    } else {
        size_t start = 0, end;
        while ((end = str.find(splt, start)) != std::string::npos) {
            result.push_back(str.substr(start, end - start));
            start = end + splt.size();
        }
        result.push_back(str.substr(start));
    }
    return result;
}

std::string Join(const std::string &sep, const std::vector<std::string> &vect) noexcept {
    std::string result;
    for (size_t i = 0; i < vect.size(); ++i) {
        result += vect[i];
        if (i != vect.size() - 1) result += sep;
    }
    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept {
    std::string result;
    bool at_line_start = true;

    for (char c : str) {
        if (c == '\t') {
            result.append(at_line_start ? tabsize - 1 : tabsize, ' ');
            at_line_start = false;
        } else {
            result.push_back(c);
            at_line_start = (c == '\n');
        }
    }
    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    std::string s1 = left;
    std::string s2 = right;
    if (ignorecase) {
        std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
        std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    }

    size_t m = s1.size();
    size_t n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
    for (size_t i = 0; i <= m; ++i) dp[i][0] = i;
    for (size_t j = 0; j <= n; ++j) dp[0][j] = j;
    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }
    return dp[m][n];
}

}