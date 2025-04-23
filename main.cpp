#include <iostream>
#include "LinkedPQ.h"

int main()
{
    LinkedPQ<char> pq;

    pq.Enqueue('A', 5);
    pq.Enqueue('C', 5);
    pq.Enqueue('Z', 9);
    pq.Enqueue('B', 5);
    pq.Enqueue('X',10);

    cout << "Initial queue:\n";
    //  should be: X(10) -> Z(9) -> A(5) -> C(5) -> B(5)
    pq.Print(); 

    char temp;

    pq.Dequeue(temp);
    cout << "\nDequeued: " << temp << '\n';
    pq.Print();

    pq.Dequeue(temp);
    cout << "\nDequeued: " << temp << '\n';
    pq.Print();

    return 0;
}
