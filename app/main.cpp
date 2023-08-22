#include <iostream>

#include "adder/add.hpp"

int main(int argc, char const* argv[])
{
    std::cout << Adder::add(1, 1) << '\n';
    return 0;
}
