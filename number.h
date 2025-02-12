#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>

using namespace std;

class Number
{
 public:
   //constructor 
   Number();
   Number(int dig);

   //input and output 
   void input();
   void output() const;

   //operators
   Number operator+(const Number in);
   Number operator*(const Number in);
   Number operator-(const Number in);
   Number operator/(const Number in);

   //comparison
   bool isEqualTo(const Number in) const;
   bool isNotEqualTo(const Number in) const;
   bool isGreaterThanOrEqualTo(const Number in) const;
   bool isLessThanOrEqualTo(const Number in) const;

   bool isZero() const;
   void increment();
   void decrement();
    
 private:
   int digit; 
};
#endif