//
//  TreeNode.h
//  lab-7
//
//  Created by İlkay Türe on 17.05.2022.
//

#ifndef TreeNode_h
#define TreeNode_h
#include <cstddef>
//#include <string>
//#include <cstring>




using namespace std;

typedef String TreeItemType;

class TreeNode { // node in the tree
    
private:
TreeNode() {}
TreeNode(const TreeItemType& nodeItem,
TreeNode *left = NULL,
TreeNode *right = NULL)
:item(nodeItem),leftChildPtr(left),rightChildPtr(right) {}
TreeItemType item; // data portion
TreeNode *leftChildPtr; // pointer to left child
TreeNode *rightChildPtr; // pointer to right child
    
friend class BinaryTree;
};


#endif /* TreeNode_h */
