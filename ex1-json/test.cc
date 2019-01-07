/*
An example JSON parser

# g++ -I. -otest -O3 test.cc jsoncpp.cpp

# echo '{"good":1}' | ./test 
Assert Hit:parsed

# echo bad | ./test 
terminate called after throwing an instance of 'std::runtime_error'
  what():  * Line 1, Column 1
  Syntax error: value, object or array expected.

Aborted (core dumped)

*/
#include <iostream>
#include "json/json.h"


extern "C" {
void local_assert(const char *message);
}

void local_assert(const char *message) {
    std::cout << "Assert Hit:" << message << "\n";
    exit(1);
}

int main(int, char**) {
    Json::Value v;
    std::cin >> v;
    local_assert("parsed");
    return 0;
}