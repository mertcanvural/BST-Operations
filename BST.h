#ifndef BST_H
#define BST_H
#include <vector>

using namespace std;

class BST
{
private:
  int comparisons;

  class BSTNode
  {
  private:
    int data;
    BSTNode *leftChild;
    BSTNode *rightChild;
    friend class BST;

  public:
    BSTNode(int &value)
    {
      data = value;
      leftChild = nullptr;
      rightChild = nullptr;
    }
    int getData()
    {
      return data;
    }
    void setData(int &value)
    {
      data = value;
    }
  };

  BSTNode *root;

public:
  BST();
  ~BST();

  // getter
  BST::BSTNode *getRoot();

  // comparisons
  void reset();
  int getCount();
  // basics
  bool insert(int value);
  bool find(int value);
  bool find_aux(int value, BST::BSTNode *np);
  bool remove(int value);

  void insertVectorElements(const vector<int> &v1);
  void removeVectorElements(const vector<int> &v1);
  
  // traversals
  void inorderTraversal(BSTNode *np);
  void postorderTraversal(BSTNode *np);
  void preorderTraversal(BSTNode *np);

  void deleteNodesAux(BSTNode *np);
  void deleteNodes();

  //
  int totalDepthCount(BST::BSTNode *np, int depth);
  int totalNodeCount(BST::BSTNode *np);
  float averageDepth();
  int findHeight();
  int findHeightAux(BST::BSTNode *np);

  void showTree();

};

#endif
