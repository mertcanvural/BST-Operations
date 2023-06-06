#include "BST.h"
#include <iostream>

using namespace std;

class BSTNode;

BST::BST()
{
    comparisons = 0;
    root = nullptr;
}

BST::~BST()
{
    deleteNodes();
}

BST::BSTNode *BST::getRoot()
{
    if (root == nullptr)
    {
        return nullptr;
    }
    return root;
}

void BST::reset()
{
    comparisons = 0;
}

int BST::getCount()
{
    return comparisons;
}

bool BST::insert(int value)
{
    if (value < 0)
        return false;

    BSTNode *newNode = new BSTNode(value);
    if (root == nullptr)
    {
        root = newNode;
        return true;
    }

    BSTNode *currNode = root;
    while (currNode != nullptr)
    {
        comparisons++;
        if (value < currNode->getData())
        {
            if (currNode->leftChild == nullptr)
            {
                currNode->leftChild = newNode;
                currNode = nullptr;
                return true;
            }
            currNode = currNode->leftChild;
        }
        else if (value > currNode->getData())
        {
            if (currNode->rightChild == nullptr)
            {
                currNode->rightChild = newNode;
                currNode = nullptr;
                return true;
            }
            currNode = currNode->rightChild;
        }
        else
        {
            delete newNode;
            newNode = nullptr;
            return false;
        }
    }
    return false;
}

bool BST::find_aux(int value, BST::BSTNode *np)
{
    if (np == nullptr)
        return false;
    comparisons++;
    if (np->getData() == value)
    {
        return true;
    }
    if (np->getData() < value)
    {
        return find_aux(value, np->rightChild);
    }
    return find_aux(value, np->leftChild);
}

bool BST::find(int value)
{
    return find_aux(value, this->root);
}

bool BST::remove(int value)
{
    BSTNode *parent = nullptr;
    BSTNode *currNode = root;

    while (currNode != nullptr)
    {
        comparisons++;
        if (currNode->getData() == value)
        {
            // leaf
            if (currNode->leftChild == nullptr && currNode->rightChild == nullptr)
            {
                if (parent == nullptr)
                {
                    root = nullptr;
                    delete currNode;
                    currNode = nullptr;
                }
                else if (parent->leftChild == currNode)
                {
                    parent->leftChild = nullptr;
                    delete currNode;
                    currNode = nullptr;
                }
                else
                {
                    parent->rightChild = nullptr;
                    delete currNode;
                    currNode = nullptr;
                }
            }
            // left child
            else if (currNode->rightChild == nullptr)
            {
                if (parent == nullptr)
                {
                    root = currNode->leftChild;
                    currNode->leftChild = nullptr;
                    delete currNode;
                }
                else if (parent->leftChild == currNode)
                {

                    parent->leftChild = currNode->leftChild;
                    currNode->leftChild = nullptr;
                    delete currNode;
                }
                else
                {
                    parent->rightChild = currNode->leftChild;
                    currNode->leftChild = nullptr;
                    delete currNode;
                }
            }
            // right child
            else if (currNode->leftChild == nullptr)
            {
                if (parent == nullptr)
                {
                    root = currNode->rightChild;
                    currNode->rightChild = nullptr;
                    delete currNode;
                }
                else if (parent->leftChild == currNode)
                {
                    parent->leftChild = currNode->rightChild;
                    currNode->rightChild = nullptr;
                    delete currNode;
                }
                else
                {
                    parent->rightChild = currNode->rightChild;
                    currNode->rightChild = nullptr;
                    delete currNode;
                }
            }
            // two children
            else
            {
                BSTNode *succNode = currNode->rightChild;
                while (succNode->leftChild != nullptr)
                {
                    succNode = succNode->leftChild;
                }
                int successorData = succNode->getData();
                remove(successorData);
                currNode->setData(successorData);
            }
            return true;
        }
        else if (currNode->getData() < value)
        {
            parent = currNode;
            currNode = currNode->rightChild;
        }
        else
        {
            parent = currNode;
            currNode = currNode->leftChild;
        }
    }
    return false; // Node not found
}

void BST::insertVectorElements(const vector<int> &v1)
{
    for (int i : v1)
    {
        this->insert(i);
    }
    return;
}

void BST::removeVectorElements(const vector<int> &v1)
{
    for (int i : v1)
    {
        this->remove(i);
    }
    return;
}

// tree traversals
void BST::inorderTraversal(BSTNode *np)
{
    if (np == nullptr)
        return;
    inorderTraversal(np->leftChild);
    cout << np->getData() << " ";
    inorderTraversal(np->rightChild);
}

void BST::preorderTraversal(BSTNode *np)
{
    if (np == nullptr)
        return;
    cout << np->getData() << " ";
    preorderTraversal(np->leftChild);
    preorderTraversal(np->rightChild);
}

void BST::postorderTraversal(BSTNode *np)
{
    if (np == nullptr)
        return;
    postorderTraversal(np->leftChild);
    postorderTraversal(np->rightChild);
    cout << np->getData() << " ";
}

void BST::deleteNodesAux(BSTNode *np)
{
    if (np != nullptr)
    {
        deleteNodesAux(np->leftChild);
        deleteNodesAux(np->rightChild);
        delete np;
    }
}

void BST::deleteNodes()
{
    BSTNode *root = this->root;
    deleteNodesAux(root);
}

int BST::findHeight()
{
    BSTNode *np = this->root;
    int height = findHeightAux(np);
    return height;
}

int BST::findHeightAux(BST::BSTNode *np)
{
    if (np == nullptr)
    {
        return -1;
    }
    int leftHeight = findHeightAux(np->leftChild) + 1;
    int rightHeight = findHeightAux(np->rightChild) + 1;
    return max(leftHeight, rightHeight);
}

int BST::totalDepthCount(BST::BSTNode *np, int depth)
{
    if (np == nullptr)
        return 0;
    int leftCount = totalDepthCount(np->leftChild, depth + 1);
    int rightCount = totalDepthCount(np->rightChild, depth + 1);

    return leftCount + rightCount + depth;
}

int BST::totalNodeCount(BST::BSTNode *np)
{
    if (np == nullptr)
        return 0;
    return 1 + totalNodeCount(np->leftChild) + totalNodeCount(np->rightChild);
}

float BST::averageDepth()
{
    BSTNode *np = this->root;
    int depthCount = totalDepthCount(np, 0);
    int nodeCount = totalNodeCount(np);
    return (depthCount / nodeCount);
}

void BST::showTree()
{
    BSTNode *np = this->getRoot();
    preorderTraversal(np);
    cout << endl;
}
