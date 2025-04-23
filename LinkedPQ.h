#ifndef LINKEDPQ_H
#define LINKEDPQ_H

#include <iostream>
using namespace std;

template <typename ItemType>
class LinkedPQ
{
private:
    struct Node
    {
        ItemType data;
        int      priority;
        Node*    next;
    };

    Node* head;  

public:
    LinkedPQ();         
    ~LinkedPQ();         

    void Enqueue(ItemType item, int priority);
    void Dequeue(ItemType& item);

    bool IsEmpty() const;
    bool IsFull()  const;

    void MakeEmpty();
    void Print() const;
};

// constructor and destructor 
template <typename ItemType>
LinkedPQ<ItemType>::LinkedPQ()
    : head(nullptr)
{}

template <typename ItemType>
LinkedPQ<ItemType>::~LinkedPQ()
{
    MakeEmpty();
}


//MakeEmpty() 
template <typename ItemType>
void LinkedPQ<ItemType>::MakeEmpty()
{
    while (head != nullptr)
    {
        Node* temp = head;
        head       = head->next;
        delete temp;
    }
}


//IsEmpty() 
template <typename ItemType>
bool LinkedPQ<ItemType>::IsEmpty() const
{
    return head == nullptr;
}

//IsFull()
template <typename ItemType>
bool LinkedPQ<ItemType>::IsFull() const
{
    try
    {
        Node* probe = new Node;
        delete probe;
        return false;
    }
    catch (bad_alloc&)
    {
        return true;
    }
}


//Enqueue
template <typename ItemType>
void LinkedPQ<ItemType>::Enqueue(ItemType item, int priority)
{

    Node* newNode   = new Node;
    newNode->data   = item;
    newNode->priority = priority;
    newNode->next   = nullptr;

    //insert in the front
    if (head == nullptr || priority > head->priority)          
    {
        newNode->next = head;
        head          = newNode;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr && curr->next->priority >= priority)
        curr = curr->next;

    newNode->next = curr->next;
    curr->next    = newNode;
}

//DeQueue 
template <typename ItemType>
void LinkedPQ<ItemType>::Dequeue(ItemType& item)
{
    if (IsEmpty())
    {
        cout << "Priority queue is empty — cannot dequeue.\n";
        return;
    }

    Node* temp = head;
    item       = head->data;
    head       = head->next;
    delete temp;
}

//print

template <typename ItemType>
void LinkedPQ<ItemType>::Print() const
{
    const Node* curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << '(' << curr->priority << ")  ->  ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

#endif   
