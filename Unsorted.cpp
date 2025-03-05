#include "ItemType.h"
#include "Unsorted.h"

// constructor and destructor 
UnsortedType::UnsortedType()
{
    length     = 0;
    capacity   = 8;
    currentPos = -1;
    info       = new ItemType[capacity];
}

UnsortedType::UnsortedType(int initCapacity)
{
    if (initCapacity < 1)
    
    initCapacity = 1;

    length     = 0;
    capacity   = initCapacity;
    currentPos = -1;
    info       = new ItemType[capacity];
}


UnsortedType::~UnsortedType()
{

    delete[] info;
    info = nullptr;
}


void UnsortedType::MakeEmpty()
{
    length = 0;
}

//4a. modify IsFull() to return true if the number of items equals the allocated array size 
bool UnsortedType::IsFull() const
{
    return (length == capacity);
}

int UnsortedType::GetLength() const
{
    return length;
}


ItemType UnsortedType::GetItem(ItemType item, bool& found)
{
    found = false;
    for (int i = 0; i < length; i++)
    {
        if (info[i].ComparedTo(item) == EQUAL)
        {
            found = true;
            return info[i];
        }
    }
    // not found
    return item;
}

//5. dynamic resizing mechanism in PutItem 
void UnsortedType::PutItem(ItemType item)
{
    // if full, resize array to double
    if (IsFull())
    {
        ResizeArray(capacity * 2);
    }

    // insert new item at end
    info[length] = item;
    length++;
}

// find 'item', swap in last item, reduce length by 1
void UnsortedType::DeleteItem(ItemType item)
{
    for (int i = 0; i < length; i++)
    {
        if (info[i].ComparedTo(item) == EQUAL)
        {
            
            info[i] = info[length - 1];
            length--;

            if (length > 0 && length < (capacity / 2))
            {
                ShrinkToFit();
            }
            return;
        }
    }
}


void UnsortedType::ResetList()
{
    currentPos = -1;
}

ItemType UnsortedType::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

ItemType& UnsortedType::operator[](int index)
{
    return info[index];
}

// halve the array if length < capacity/2
void UnsortedType::ShrinkToFit()
{
    int newCap = capacity / 2;
    if (newCap < 1)
        newCap = 1;
    // dont go below
    if (newCap < length)
        newCap = length;

    ResizeArray(newCap);
}

void UnsortedType::ResizeArray(int newCap)
{
    // new array 
    ItemType* newArr = new ItemType[newCap];

    for (int i = 0; i < length; i++)
    {
        newArr[i] = info[i];
    }

    // delete the old
    delete[] info;

    // Update
    info     = newArr;
    capacity = newCap;
}