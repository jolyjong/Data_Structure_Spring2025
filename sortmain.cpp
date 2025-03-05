#include <iostream>
using namespace std;

#include "Unsorted.h"

int main()
{
    // 1a)
    UnsortedType list1;

    // show list is empty 
    cout << "list1 length = " << list1.GetLength() << endl;
    cout << (list1.IsFull() ? "list1 is FULL" : "list1 is NOT full") << endl;

    // put items
    for (int i = 1; i <= 8; i++)
    {
        ItemType it;
        it.Initialize(i * 10);
        list1.PutItem(it);
    }
    cout << "After inserting 8 items:\n";
    cout << "list1 length = " << list1.GetLength() << endl;
    cout << (list1.IsFull() ? "list1 is FULL" : "list1 is NOT full") << endl;


    ItemType extra;
    extra.Initialize(999);
    list1.PutItem(extra);


    cout << "After inserting 9th item:\n";
    cout << "list1 length = " << list1.GetLength() << endl;
    cout << (list1.IsFull() ? "list1 is FULL" : "list1 is NOT full") << endl;

    
    cout << "list1 contents:\n";
    for (int i = 0; i < list1.GetLength(); i++)
    {
        list1[i].Print(cout);
        cout << " ";
    }
    cout << "\n\n";

    // delete an item 
    ItemType toDelete;
    toDelete.Initialize(20);
    list1.DeleteItem(toDelete);  // remove "20"
    cout << "After deleting 20:\n";
    cout << "list1 length = " << list1.GetLength() << endl;

    // Possibly triggers ShrinkToFit if the list is < half capacity
    // (with 8 items left, capacity is 16 => 8 < 16/2 => equals 8, so still 50% => might not shrink yet)
    cout << (list1.IsFull() ? "list1 is FULL" : "list1 is NOT full") << endl;

    // print again
    cout << "list1 contents:\n";
    for (int i = 0; i < list1.GetLength(); i++)
    {
        list1[i].Print(cout);
        cout << " ";
    }
    cout << "\n\n";

    // remove more items 
    ItemType temp;
    temp.Initialize(30);
    list1.DeleteItem(temp); // remove "30"
    temp.Initialize(40);
    list1.DeleteItem(temp);
    temp.Initialize(50);
    list1.DeleteItem(temp);
    cout << "After removing 30,40,50:\n";
    cout << "list1 length = " << list1.GetLength() << endl;

    // check
    for (int i = 0; i < list1.GetLength(); i++)
    {
        list1[i].Print(cout);
        cout << " ";
    }
    cout << "\n";

    // demonstrate param constructor
    UnsortedType list2(2);
    cout << "\nlist2 (capacity=2) created. Insert 2 items: \n";

    ItemType a,b;
    a.Initialize(111);
    b.Initialize(222);
    list2.PutItem(a);
    list2.PutItem(b);

    cout << "list2 length = " << list2.GetLength() << endl;

    // insert 3rd => triggers re-size to capacity = 4
    ItemType c;
    c.Initialize(333);
    list2.PutItem(c);

    cout << "After inserting 3rd item into list2:\n";
    cout << "list2 length = " << list2.GetLength() << endl;

    // final 
    for (int i = 0; i < list2.GetLength(); i++)
    {
        list2[i].Print(cout);
        cout << " ";
    }
    cout << "\n";

    return 0;
}
