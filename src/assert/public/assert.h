#pragma once

#include <iostream>

#define check(condition) \
do \
{\
    if((condition))\
    {\
        std::cerr << "Check failed! " << #condition \
        << " in " __FILE__ \
        << " line " << __LINE__ << std::endl;\
    }\
} while(0)