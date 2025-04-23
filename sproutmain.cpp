#include <iostream>
#include <fstream>
#include "sprout.h"
using namespace std;

int main()
{
    TreeType bst;


    // test insert 
    const char vals[] = { 'F','B','G','A','D','I','C','E','H' };
    cout << "Inserting:";
    for (int i = 0; i < int(sizeof(vals)/sizeof(vals[0])); ++i) {
        cout << ' ' << vals[i];
        bst.PutItem(vals[i]);
    }
    cout << "\n\n";

    // test stats 
    cout << "Length   : " << bst.GetLength() << "\n"
         << "IsEmpty  : " << (bst.IsEmpty()? "yes":"no")  << "\n"
         << "IsFull   : " << (bst.IsFull()?  "yes":"no")  << "\n\n";

    // test print 
    ofstream out("bst_inorder.txt");
    bst.Print(out);
    out.close();
    cout << "Wrote bst_inorder.txt\n\n";

    // test search 
    bool found;
    char key = 'D';
    bst.GetItem(key, found);
    cout << "Search 'D': " << (found? "found":"not found") << "\n\n";

    // test IsBST 
    cout << "IsBST()? " << (bst.IsBST()? "yes":"no") << "\n\n";

    // test successor / predecessor
    int s = bst.findSuccessor('D');
    int p = bst.findPredecessor('D');
    cout << "Successor of D   : " << (s==-1? "none": string(1,char(s))) << "\n"
         << "Predecessor of D : " << (p==-1? "none": string(1,char(p))) << "\n\n";

    // test path 
    cout << "Path to 'E': ";
    bst.printPathToNote('E');
    cout << "\n";

    // test leaf count
    cout << "Leaf count: " << bst.countLeaves() << "\n\n";

    // test delete 'B' & reprint
    cout << "Deleting 'B'...\n";
    bst.DeleteItem('B');
    ofstream out2("bst_after_delete.txt");
    bst.Print(out2);
    out2.close();
    cout << "Wrote bst_after_delete.txt\n";

    return 0;
}
