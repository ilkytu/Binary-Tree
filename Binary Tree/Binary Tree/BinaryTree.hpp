//
//  BinaryTree.hpp
//  lab-7
//
//  Created by İlkay Türe on 17.05.2022.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
typedef void (*FunctionType)(TreeItemType& anItem);

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(TreeNode *nodePtr);
    BinaryTree(const TreeItemType& rootItem);
    BinaryTree(const TreeItemType& rootItem, BinaryTree& leftTree, BinaryTree& rightTree);
    BinaryTree(const BinaryTree& tree);
    ~BinaryTree();
    bool isEmpty() const;
    void attachLeft(const TreeItemType& newItem);
    void attachRight(const TreeItemType& newItem);
    void attachLeftSubtree(BinaryTree& leftTree);
    void attachRightSubtree(BinaryTree& rightTree);
    void copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const;
    void destroyTree(TreeNode *& treePtr);
    void preorderTraverse(FunctionType visit);
    void inorderTraverse(FunctionType visit);
    void postorderTraverse(FunctionType visit);
    void preorder(TreeNode *treePtr, FunctionType visit);
    void inorder(TreeNode *treePtr, FunctionType visit);
    void postorder(TreeNode *treePtr, FunctionType visit);
    int add();
private:
    TreeNode* root;
    int addHelp(TreeNode* treePtr);
};

#endif // BINARYTREE_H_INCLUDED


