#ifndef UNSORTEDTYPE_H
#define UNSORTEDTYPE_H

#include "ItemType.h"
#include <iostream>
using namespace std;

class UnsortedType
{
public:
    // 2a. Default constructor: capacity = 8
    UnsortedType();

    // 2b. Parameterized constructor: user can specify initial capacity
    UnsortedType(int initCapacity);

    // 3. Destructor: frees dynamic memory.
    // needed because we allocate our array with 'new'
    ~UnsortedType();

    void MakeEmpty();
    bool IsFull() const;
    int GetLength() const;

    ItemType GetItem(ItemType item, bool& found);

    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();

    ItemType GetNextItem();


    // 4b. Subscript operator: provides read/write access
    ItemType& operator[](int index);

    // 6. ShrinkToFit: reduce array size when length < 50% of capacity
    void ShrinkToFit();

private:
    int length;      
    int capacity;    
    
    // 1.
    ItemType* info; 
    int currentPos;  
    
    void ResizeArray(int newCap);

};

#endif
