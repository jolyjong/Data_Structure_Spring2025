#include <iostream>
#include "number.h"
using namespace std;

int main()
{
    //testing both constructors 
    Number n1;      
    Number n2(2);   

    cout << "Enter an integer for n1: ";
    n1.input();      

    cout << "n1 = ";
    n1.output();    
    cout << endl;

    cout << "n2 = ";
    n2.output();
    cout << endl;

    // testing + operator
    Number sum = n1 + n2;
    cout << "n1 + n2 = ";
    sum.output();
    cout << endl;

    // testing - operator 
    Number diff = n1 - n2;
    cout << "n1 - n2 = ";
    diff.output();
    cout << endl;

    // testing all the comparison 
    if (n1.isEqualTo(n2))
        cout << "n1 == n2\n";
    else if (n1.isNotEqualTo(n2))
        cout << "n1 != n2\n";

    if (n1.isZero())
        cout << "n1 is zero\n";
    else
        cout << "n1 is not zero\n";
        //test (/) here because if n1 is zero then it'll be out of bound
        Number quotient = n1 / n2; 
        cout << "n1 / n2 = ";
        quotient.output();
        cout << endl;

    
    // testing ++ and -- 
    cout << "n1++ \n";
    n1.increment();
    cout << "n1 now is = ";
    n1.output();
    cout << endl;

    cout << "n2-- \n";
    n2.decrement();
    cout << "n2 now is = ";
    n2.output();
    cout << endl;

    // testing * 
    Number product = n1 * n2;
    cout << "n1 * n2 = ";
    product.output();
    cout << endl;

    

    return 0;
}
