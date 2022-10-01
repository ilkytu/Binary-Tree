//
//  BinaryTree.cpp
//  lab-7
//
//  Created by İlkay Türe on 17.05.2022.
//
#include <iostream>
#include "BinaryTree.hpp"
#include <cstddef>

using namespace std;

// Default constructor
BinaryTree::BinaryTree() : root(NULL)
{
}

// Protected constructor
BinaryTree::BinaryTree(TreeNode *nodePtr) : root(nodePtr)
{
}

// Constructor
BinaryTree::BinaryTree(const TreeItemType& rootItem)
{
    root = new TreeNode(rootItem, NULL, NULL);
}

// Constructor
BinaryTree::BinaryTree(const TreeItemType& rootItem,
                       BinaryTree& leftTree, BinaryTree& rightTree)
{
    root = new TreeNode(rootItem, NULL, NULL);
    attachLeftSubtree(leftTree);
    attachRightSubtree(rightTree);
}

bool BinaryTree::isEmpty() const
{
    return (root == NULL);
}  // end isEmpty

void BinaryTree::attachLeft(const TreeItemType& newItem)
{
    if (isEmpty())
        cout << "Exception: Empty tree" << endl;
    else if (root->leftChildPtr != NULL)
        cout << "Exception: Cannot overwrite left subtree" << endl;
    else  // Assertion: nonempty tree; no left child
    {
        root->leftChildPtr = new TreeNode(newItem, NULL, NULL);
    }
}  // end attachLeft

void BinaryTree::attachRight(const TreeItemType& newItem)
{
    if (isEmpty())
        cout << "Exception: Empty tree" << endl;
    else if (root->rightChildPtr != NULL)
        cout << "Exception: Cannot overwrite right subtree" << endl;
    else  // Assertion: nonempty tree; no right child
    {
        root->rightChildPtr = new TreeNode(newItem, NULL, NULL);
    }
}  // end attachRight

void BinaryTree::attachLeftSubtree(BinaryTree& leftTree)
{
    // Assertion: nonempty tree; no left child
    if (!isEmpty() && (root->leftChildPtr == NULL))
    {
        root->leftChildPtr = leftTree.root;
        leftTree.root = NULL;
    }
}   // end attachLeftSubtree

void BinaryTree::attachRightSubtree(BinaryTree& rightTree)
{
    if (!isEmpty() && (root->rightChildPtr == NULL))
    {
        root->rightChildPtr = rightTree.root;
        rightTree.root = NULL;
    }
}   // end attachRightSubtree

// Copy constructor
BinaryTree::BinaryTree(const BinaryTree& tree)
{
    copyTree(tree.root, root);
}

// Uses preorder traversal for the copy operation
// (Visits first the node and then the left and right children)
void BinaryTree::copyTree(TreeNode *treePtr, TreeNode *& newTreePtr) const
{
    if (treePtr != NULL)   // copy node
    {
        newTreePtr = new TreeNode(treePtr->item, NULL, NULL);
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else
        newTreePtr = NULL; // copy empty tree
}

// Destructor
BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

// Uses postorder traversal for the destroy operation
// (Visits first the left and right children and then the node)
void BinaryTree::destroyTree(TreeNode *& treePtr)
{
    if (treePtr != NULL)
    {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}   // end destroyTree

void BinaryTree::preorderTraverse(FunctionType visit)
{
    preorder(root, visit);
}

void BinaryTree::inorderTraverse(FunctionType visit)
{
    inorder(root, visit);
}

void BinaryTree::postorderTraverse(FunctionType visit)
{
    postorder(root, visit);
}

void BinaryTree::preorder(TreeNode *treePtr, FunctionType visit)
{
    if (treePtr != NULL)
    {
        visit(treePtr->item);
        preorder(treePtr->leftChildPtr, visit);
        preorder(treePtr->rightChildPtr, visit);
    }
}

void BinaryTree::inorder(TreeNode *treePtr, FunctionType visit)
{
    if (treePtr != NULL)
    {
        inorder(treePtr->leftChildPtr, visit);
        visit(treePtr->item);
        inorder(treePtr->rightChildPtr, visit);
    }
}

void BinaryTree::postorder(TreeNode *treePtr, FunctionType visit)
{
    if (treePtr != NULL)
    {
        postorder(treePtr->leftChildPtr, visit);
        postorder(treePtr->rightChildPtr, visit);
        visit(treePtr->item);
    }
}

int BinaryTree::add()
{
    return addHelp(root);
}

// method 1: Function to find sum of all values in the Binary Tree
int BinaryTree::addHelp(TreeNode* treePtr)
{
    if (treePtr == NULL)
        return 0;
    else
        return treePtr->item + addHelp(treePtr->leftChildPtr) + addHelp(treePtr->rightChildPtr);
}

/*
// method 2: Function to find sum of all values in the Binary Tree
int BinaryTree::addHelp(TreeNode* treePtr)
{
    if (treePtr == NULL)
        return 0;
    else
    {
        int sum = 0;

        stack<TreeNode*> s;
        s.push(treePtr);

        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();

            sum += temp->item;

            if(temp->leftChildPtr)
            {
                s.push(temp->leftChildPtr);
            }

            if(temp->rightChildPtr)
            {
                s.push(temp->rightChildPtr);
            }
        }
        return sum;
    }
}
*/
