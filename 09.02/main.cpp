#include "Logger.hpp"

namespace {

void foo() 
{
    logger::Logger my_logger;
}

}

int main() 
{
    logger::Logger my_logger;

    foo();
}