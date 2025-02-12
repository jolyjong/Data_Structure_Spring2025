#include "number.h"

//constructor 
Number::Number() : digit(0)
{
}

Number::Number(int dig) : digit(dig)
{
}

void Number::input()
{
    cin >> digit; 
}

void Number::output() const
{
    cout << digit;
}

// operators 
Number Number::operator+(const Number in)
{
    Number temp;
    temp.digit = this->digit + in.digit;
    return temp;
}

Number Number::operator-(const Number in)
{
    Number temp;
    temp.digit = this->digit - in.digit;
    return temp;
}

Number Number::operator*(const Number in)
{
    Number temp;
    temp.digit = this->digit * in.digit;
    return temp;
}

Number Number::operator/(const Number in)
{
    Number temp;
    temp.digit = this->digit / in.digit;
    return temp;
}

// comparison 
bool Number::isEqualTo(const Number in) const
{
    return (digit == in.digit);
}

bool Number::isNotEqualTo(const Number in) const
{
    return (digit != in.digit);
}

bool Number::isGreaterThanOrEqualTo(const Number in) const
{
    return (digit >= in.digit);
}

bool Number::isLessThanOrEqualTo(const Number in) const
{
    return (digit <= in.digit);
}

bool Number::isZero() const
{
    return (digit == 0);
}

//++ and -- 
void Number::increment()
{
    digit++;
}

void Number::decrement()
{
    digit--;
}
