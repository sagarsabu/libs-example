#pragma once

namespace Adder
{
template<typename Addable>
Addable add(const Addable& a, const Addable& b)
{
    return a + b;
};
} // namespace Adder

