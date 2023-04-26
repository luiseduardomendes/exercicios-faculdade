#pragma once
#include <iostream>
#include <string>
#include "Expression.hpp"

class Symbol
{
private:
    std::string _symbol;
public:
    Symbol();
    Symbol(std::string _symbol);
    template <typename T>
    Expression operator+(T );
    template <typename T>
    Expression operator*(T );
    template <typename T>
    Expression operator/(T );
    template <typename T>
    Expression operator-(T );

};