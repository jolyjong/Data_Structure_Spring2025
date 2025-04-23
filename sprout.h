#ifndef SPROUT_H
#define SPROUT_H

#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

typedef char ItemType;

struct TreeNode
{
    ItemType   info;
    TreeNode*  left;
    TreeNode*  right;
};

class TreeType
{
public:
    // Problem 1
    TreeType();                           // a) constructor
    ~TreeType();                          // b) destructor
    TreeType(const TreeType& original);   // copy constructor

    int  GetLength() const;               // c) get length
    void MakeEmpty();                     //    clear the tree

    bool IsEmpty() const;                 // d) is empty?
    bool IsFull()  const;                 // e) is full?

    ItemType GetItem(ItemType item, bool& found); // f) retrieve
    void     PutItem(ItemType item);             //    insert
    void     DeleteItem(ItemType item);          //    delete

    void Print(ofstream& outFile) const;  // g) inorder print

    // Problem 2
    bool IsBST() const;

    // Problem 3
    int findSuccessor(int key)   const;
    int findPredecessor(int key) const;

    // Problem 4
    bool printPathToNote(int key) const;

    // Problem 5
    int countLeaves() const;

private:
    TreeNode* root;

    // helpers for core ops
    static TreeNode* CopyTree(TreeNode* src);
    static void Destroy(TreeNode*& t);
    static int CountNodes(TreeNode* t);
    static bool IsBSTHelper(TreeNode* t, int lo, int hi);
    static void InsertNode(TreeNode*& t, ItemType val);
    static void DeleteNode(TreeNode*& t);
    static void Delete(TreeNode*& t, ItemType val);
    static void Retrieve(TreeNode* t, ItemType& item, bool& found);
    static void PrintTree(TreeNode* t, ofstream& out);
    

    // successor/predecessor helpers
    static TreeNode* FindNode(TreeNode* t, char key);
    static TreeNode* FindMin (TreeNode* t);
    static TreeNode* FindMax (TreeNode* t);

    // path helper
    static bool PrintPathHelper(TreeNode* t, char key);

    // leaf count helper
    static int CountLeavesHelper(TreeNode* t);
};

#endif 
