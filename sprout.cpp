#include "sprout.h"
#include <iostream>
#include <new>
#include <climits>
using namespace std;

//Problem 1. a) and b) 
//constructor and destructor 

TreeType::TreeType() : root(nullptr) {}

TreeType::TreeType(const TreeType& other)
  : root(nullptr)
{
    if (other.root) {
        root = CopyTree(other.root);
    }
}

TreeType::~TreeType()
{
    MakeEmpty();
}

// copy and destroy 

TreeNode* TreeType::CopyTree(TreeNode* src)
{
    if (!src) return nullptr;
    TreeNode* node = new TreeNode;
    node->info  = src->info;
    node->left  = CopyTree(src->left);
    node->right = CopyTree(src->right);
    return node;
}

void TreeType::Destroy(TreeNode*& t)
{
    if (!t) return;
    Destroy(t->left);
    Destroy(t->right);
    delete t;
    t = nullptr;
}

// problem 1. c)
// getLength

int TreeType::CountNodes(TreeNode* t)
{
    if (!t) return 0;
    return 1 + CountNodes(t->left) + CountNodes(t->right);
}

int TreeType::GetLength() const
{
    return CountNodes(root);
}

void TreeType::MakeEmpty()
{
    Destroy(root);
}

// Problem 1. d) and e) 
bool TreeType::IsEmpty() const
{
    return root == nullptr;
}

bool TreeType::IsFull() const
{
    try {
        TreeNode* tmp = new TreeNode;
        delete tmp;
        return false;
    } catch (bad_alloc&) {
        return true;
    }
}


void TreeType::InsertNode(TreeNode*& t, ItemType v)
{
    if (!t) {
        t = new TreeNode;
        t->info  = v;
        t->left  = nullptr;
        t->right = nullptr;
    }
    else if (v < t->info)
        InsertNode(t->left,  v);
    else
        InsertNode(t->right, v);
}

void TreeType::PutItem(ItemType item)
{
    InsertNode(root, item);
}

void TreeType::DeleteNode(TreeNode*& n)
{
    if (!n->left && !n->right) {
        delete n;
        n = nullptr;
    }
    else if (!n->left) {
        TreeNode* tmp = n;
        n = n->right;
        delete tmp;
    }
    else if (!n->right) {
        TreeNode* tmp = n;
        n = n->left;
        delete tmp;
    }
    else {
        // replace with inorder predecessor
        TreeNode* pp = n;
        TreeNode* pred = n->left;
        while (pred->right) {
            pp = pred;
            pred = pred->right;
        }
        n->info = pred->info;
        if (pp == n) pp->left  = pred->left;
        else         pp->right = pred->left;
        delete pred;
    }
}

void TreeType::Delete(TreeNode*& t, ItemType v)
{
    if (!t) return;
    if      (v < t->info) Delete(t->left,  v);
    else if (v > t->info) Delete(t->right, v);
    else                   DeleteNode(t);
}

void TreeType::DeleteItem(ItemType item)
{
    Delete(root, item);
}

//Problem 1. f) GetItem 
void TreeType::Retrieve(TreeNode* t, ItemType& item, bool& found)
{
    if (!t) {
        found = false;
    }
    else if (item < t->info) {
        Retrieve(t->left, item, found);
    }
    else if (item > t->info) {
        Retrieve(t->right, item, found);
    }
    else {
        found = true;
        item  = t->info;
    }
}


ItemType TreeType::GetItem(ItemType item, bool& found)
{
    Retrieve(root, item, found);
    return item;
}

// Problem 1. g) 

void TreeType::PrintTree(TreeNode* t, ofstream& outFile)
{
    if (!t) return;
    PrintTree(t->left,  outFile);
    outFile << t->info << ' ';
    PrintTree(t->right, outFile);
}

void TreeType::Print(ofstream& outFile) const
{
    PrintTree(root, outFile);
}

// Problem 2) 
// IsBST 

bool TreeType::IsBSTHelper(TreeNode* t, int lo, int hi)
{
    if (!t) return true;
    if (t->info <= lo || t->info >= hi) return false;
    return IsBSTHelper(t->left,  lo, t->info)
        && IsBSTHelper(t->right, t->info, hi);
}

bool TreeType::IsBST() const
{
    return IsBSTHelper(root, INT_MIN, INT_MAX);
}

// Problem 3 Successor and Predessor 

TreeNode* TreeType::FindNode(TreeNode* t, char key)
{
    if (!t) return nullptr;
    if (key == t->info) return t;
    return (key < t->info)
        ? FindNode(t->left,  key)
        : FindNode(t->right, key);
}

TreeNode* TreeType::FindMin(TreeNode* t)
{
    while (t && t->left) t = t->left;
    return t;
}

TreeNode* TreeType::FindMax(TreeNode* t)
{
    while (t && t->right) t = t->right;
    return t;
}

int TreeType::findSuccessor(int key) const
{
    char k = static_cast<char>(key);
    TreeNode* n = FindNode(root, k);
    if (!n) return -1;
    if (n->right) return FindMin(n->right)->info;
    int succ = -1;
    TreeNode* cur = root;
    while (cur) {
        if      (k < cur->info) { succ = cur->info; cur = cur->left; }
        else if (k > cur->info) cur = cur->right;
        else break;
    }
    return succ;
}

int TreeType::findPredecessor(int key) const
{
    char k = static_cast<char>(key);
    TreeNode* n = FindNode(root, k);
    if (!n) return -1;
    if (n->left) return FindMax(n->left)->info;
    int pred = -1;
    TreeNode* cur = root;
    while (cur) {
        if      (k > cur->info) { pred = cur->info; cur = cur->right; }
        else if (k < cur->info) cur = cur->left;
        else break;
    }
    return pred;
}

// Problem 4) print Path 

bool TreeType::PrintPathHelper(TreeNode* t, char key)
{
    if (!t) return false;
    cout << t->info << ' ';
    if (t->info == key) { cout << '\n'; return true; }
    return (key < t->info)
        ? PrintPathHelper(t->left,  key)
        : PrintPathHelper(t->right, key);
}

bool TreeType::printPathToNote(int key) const
{
    return PrintPathHelper(root, static_cast<char>(key));
}

// Problem 5 count leaves 

int TreeType::CountLeavesHelper(TreeNode* t)
{
    if (!t) return 0;
    if (!t->left && !t->right) return 1;
    return CountLeavesHelper(t->left)
         + CountLeavesHelper(t->right);
}

int TreeType::countLeaves() const
{
    return CountLeavesHelper(root);
}
