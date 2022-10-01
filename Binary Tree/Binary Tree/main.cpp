
#include "BinaryTree.hpp"
#include <iostream>


using namespace std;

void display(TreeItemType& anItem)
{
    cout << anItem << " ";
}

int main()
{
    BinaryTree bt(2);
    bt.attachRight(9);

    BinaryTree bt3(6);
    bt3.attachLeft(5);
    bt3.attachRight(11);

    BinaryTree bt2(7);
    bt2.attachLeft(2);
    bt2.attachRightSubtree(bt3);

    bt.attachLeftSubtree(bt2);

    // display inorder traversal
    cout << "Inorder Traversal: " << endl;
    bt.inorderTraverse(display);

    // get sum of all values in the BT
    cout << endl << endl << "Sum of all values in the Binary Tree : " << bt.add() << endl;

    return 0;
}
