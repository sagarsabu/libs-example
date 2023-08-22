#include <iostream>

#include "adder/add.hpp"
#include "helper.hpp"

void useAdder()
{
    std::cout << "Adder::add(100, 100.1)= " << Adder::add<float>(100, 100.1) << '\n';
}
