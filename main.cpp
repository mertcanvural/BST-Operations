#include "BST.h"
#include <iostream>
#include <ctime>

using namespace std;

// random
void shuffle(vector<int> &v, int S);
void shake(vector<int> &v, int S, int R);

int treeNum = 0;

// the results of the experiments
vector<int> insertOperationCounts;
vector<int> findOperationCounts;
vector<float> averageDepths;
vector<int> heights;
vector<int> removeOperationCounts;

// experiment functions
void experimentInsert(vector<int> &v, BST &aTree);
void experimentFind(BST &aTree);
void experimentAverageDepth(BST &aTree);
void experimentHeight(BST &aTree);
void experimentRemove(vector<int> &v, BST &aTree);

// results
void showResults();
void treeDescription(int i);

int main()
{
  srand(time(nullptr));
  // Empty trees
  BST aTree0, aTree1, aTree2, aTree3, aTree4, aTree5, aTree6, aTree7;

  // Initial array ( will be in ascending order )
  vector<int> v0;

  // Experimenting with different sizes
  // vector<int> nodeCounts = {1000, 5000, 20000, 100000, 2000000};
  vector<int> nodeCounts = {1000, 5000, 20000};

  // Experiments
  for (int nodeCount : nodeCounts)
  {
    for (int i = 0; i < nodeCount; ++i)
    {
      v0.push_back(i);
    }
    // deep copy of v0
    vector<int> v1(v0);
    vector<int> v2(v0);
    vector<int> v3(v0);
    vector<int> v4(v0);
    vector<int> v5(v0);
    vector<int> v6(v0);
    vector<int> v7(v0);

    // changing the order of the elements of the vectors
    //
    shuffle(v1, nodeCount);
    //
    shuffle(v2, nodeCount / 2);
    //
    shuffle(v3, nodeCount % 11);
    //
    shake(v4, nodeCount, nodeCount);
    //
    shake(v5, nodeCount, nodeCount % 11);
    //
    shake(v6, nodeCount % 11, nodeCount);
    //
    shake(v7, nodeCount % 11, nodeCount % 11);

    // insert
    experimentInsert(v0, aTree0);
    experimentInsert(v1, aTree1);
    experimentInsert(v2, aTree2);
    experimentInsert(v3, aTree3);
    experimentInsert(v4, aTree4);
    experimentInsert(v5, aTree5);
    experimentInsert(v6, aTree6);
    experimentInsert(v7, aTree7);
    // reset
    treeNum = 0;
    aTree0.reset();
    aTree1.reset();
    aTree2.reset();
    aTree3.reset();
    aTree4.reset();
    aTree5.reset();
    aTree6.reset();
    aTree7.reset();
    // find
    experimentFind(aTree0);
    experimentFind(aTree1);
    experimentFind(aTree2);
    experimentFind(aTree3);
    experimentFind(aTree4);
    experimentFind(aTree5);
    experimentFind(aTree6);
    experimentFind(aTree7);
    // reset
    treeNum = 0;
    aTree0.reset();
    aTree1.reset();
    aTree2.reset();
    aTree3.reset();
    aTree4.reset();
    aTree5.reset();
    aTree6.reset();
    aTree7.reset();
    // average depth
    experimentAverageDepth(aTree0);
    experimentAverageDepth(aTree1);
    experimentAverageDepth(aTree2);
    experimentAverageDepth(aTree3);
    experimentAverageDepth(aTree4);
    experimentAverageDepth(aTree5);
    experimentAverageDepth(aTree6);
    experimentAverageDepth(aTree7);
    // reset
    treeNum = 0;
    aTree0.reset();
    aTree1.reset();
    aTree2.reset();
    aTree3.reset();
    aTree4.reset();
    aTree5.reset();
    aTree6.reset();
    aTree7.reset();
    // height
    experimentHeight(aTree0);
    experimentHeight(aTree1);
    experimentHeight(aTree2);
    experimentHeight(aTree3);
    experimentHeight(aTree4);
    experimentHeight(aTree5);
    experimentHeight(aTree6);
    experimentHeight(aTree7);
    // reset
    treeNum = 0;
    aTree0.reset();
    aTree1.reset();
    aTree2.reset();
    aTree3.reset();
    aTree4.reset();
    aTree5.reset();
    aTree6.reset();
    aTree7.reset();
    // remove
    experimentRemove(v0, aTree0);
    experimentRemove(v1, aTree1);
    experimentRemove(v2, aTree2);
    experimentRemove(v3, aTree3);
    experimentRemove(v4, aTree4);
    experimentRemove(v5, aTree5);
    experimentRemove(v6, aTree6);
    experimentRemove(v7, aTree7);
    // reset
    treeNum = 0;
    aTree0.reset();
    aTree1.reset();
    aTree2.reset();
    aTree3.reset();
    aTree4.reset();
    aTree5.reset();
    aTree6.reset();
    aTree7.reset();

    // Clean up
    v0.clear();
  }
  showResults();
}

/*
vector<int> insertOperationCounts;
vector<int> findOperationCounts;
vector<float> averageDepths;
vector<int> heights;
vector<int> removeOperationCounts;

8 trees
each vector's
first 8 elements are for trees with 1000 elements
8 to 16 elements are for trees with 5000 elements
17 to 23 elements are for trees with 20000 elements

    shuffle(v1, nodeCount);
    //
    shuffle(v2, nodeCount / 2);
    //
    shuffle(v3, nodeCount % 11);
    //
    shake(v4, nodeCount, nodeCount);
    //
    shake(v5, nodeCount, nodeCount % 11);
    //
    shake(v6, nodeCount % 11, nodeCount);
    //
    shake(v7, nodeCount % 11, nodeCount % 11);


*/
void showResults()
{
  for (int i = 0; i < 8; ++i)
  {
    cout << endl;
    cout << "==============="
         << " Tree" << i << "'s results ===============" << endl;
    treeDescription(i);
    cout << "-------------------------------------------" << endl;
    cout << "For 1000 nodes:" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "   Average depth: " << averageDepths.at(i) << endl;
    cout << "   Height: " << heights.at(i) << endl;
    cout << "   Number of comparisons resulted from finding 1000 random elements in between 0-20000: " << findOperationCounts.at(i) << endl;
    cout << "   Number of comparisons resulted from inserting 1000 elements: " << insertOperationCounts.at(i) << endl;
    cout << "   Number of comparisons resulted from removing 1000 elements: " << removeOperationCounts.at(i) << endl;
    cout << "-------------------------------------------" << endl;
    cout << "For 5000 nodes:" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "   Average depth: " << averageDepths.at(i + 8) << endl;
    cout << "   Height: " << heights.at(i + 8) << endl;
    cout << "   Number of comparisons resulted from finding 1000 random elements in between 0-20000: " << findOperationCounts.at(i + 8) << endl;
    cout << "   Number of comparisons resulted from inserting 1000 elements: " << insertOperationCounts.at(i + 8) << endl;
    cout << "   Number of comparisons resulted from removing 1000 elements: " << removeOperationCounts.at(i + 8) << endl;
    cout << "-------------------------------------------" << endl;
    cout << "For 20000 nodes:" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "   Average depth: " << averageDepths.at(i + 16) << endl;
    cout << "   Height: " << heights.at(i + 16) << endl;
    cout << "   Number of comparisons resulted from finding 1000 random elements in between 0-20000: " << findOperationCounts.at(i + 16) << endl;
    cout << "   Number of comparisons resulted from inserting 1000 elements: " << insertOperationCounts.at(i + 16) << endl;
    cout << "   Number of comparisons resulted from removing 1000 elements: " << removeOperationCounts.at(i + 16) << endl;
    cout << endl;
  }
}



void treeDescription(int i)
{
  switch (i % 8)
  {
  case 0:
    cout << "Tree0's elements were inserted in ascending order." << endl;
    break;
  case 1:
    cout << "Tree1's elements were called with : shuffle(v1, nodeCount)" << endl;
    break;
  case 2:
    cout << "Tree2's elements were called with : shuffle(v2, nodeCount / 2)" << endl;
    break;
  case 3:
    cout << "Tree3's elements were called with : shuffle(v3, nodeCount % 11)" << endl;
    break;
  case 4:
    cout << "Tree4's elements were called with : shake(v4, nodeCount, nodeCount)" << endl;
    break;
  case 5:
    cout << "Tree5's elements were called with : shake(v5, nodeCount, nodeCount % 11)" << endl;
    break;
  case 6:
    cout << "Tree6's elements were called with : shake(v6, nodeCount % 11, nodeCount)" << endl;
    break;
  case 7:
    cout << "Tree7's elements were called with : shake(v7, nodeCount % 11, nodeCount % 11)" << endl;
    break;
  }
}


void experimentRemove(vector<int> &v, BST &aTree)
{
  aTree.removeVectorElements(v);
  removeOperationCounts.push_back(aTree.getCount());
  treeNum++;
}

void experimentInsert(vector<int> &v, BST &aTree)
{
  aTree.insertVectorElements(v);
  insertOperationCounts.push_back(aTree.getCount());
  treeNum++;
}

void experimentFind(BST &aTree)
{
  for (int i = 0; i < 1000; ++i)
  {
    int randNum = rand() % 20000;
    aTree.find(randNum);
  }
  findOperationCounts.push_back(aTree.getCount());
  treeNum++;
}

void experimentAverageDepth(BST &aTree)
{
  averageDepths.push_back(aTree.averageDepth());
  treeNum++;
}

void experimentHeight(BST &aTree)
{
  heights.push_back(aTree.findHeight());
  treeNum++;
}

void shuffle(vector<int> &v, int S)
{
  for (int i = 0; i < S; ++i)
  {
    int index1 = rand() % v.size();
    int index2 = rand() % v.size();
    // swap items;
    int temp = v[index1];
    v[index1] = v[index2];
    v[index2] = temp;
  }
}

void shake(vector<int> &v, int S, int R)
{
  // size of the vector
  int len = v.size();
  for (int i = 0; i < S; ++i)
  {
    // 1 : left , 0 : right
    int direction = rand() % 2;
    // picking a random index in the list
    int randIndex = rand() % len;
    // shiftCount number of times the element will be shifted
    int shiftCount = rand() % (R + 1);
    // getting the element into a temporary variable
    int num = v.at(randIndex);
    // shake left
    if (direction)
    {
      int target = randIndex - shiftCount;
      // prevent wrapping by setting to zero when target becomes negative
      if (target < 0)
        target = 0;
      // shift the vector elements to right and place the num at the index target
      for (int j = randIndex; j > target; --j)
      {
        v[j] = v[j - 1];
      }
      v[target] = num;
      // cout << "randIndex:" << randIndex <<  "| " << "shiftCount" << shiftCount << endl;
      // cout << "Shifting " << num << " to " << (direction ? "left" : "right") << " by " << shiftCount << " times " << endl;
    }
    // shake right
    else
    {
      int target = randIndex + shiftCount;
      if (target >= len)
        target = len - 1;
      for (int j = randIndex; j < target; ++j)
      {
        v[j] = v[j + 1];
      }
      v[target] = num;
      // cout << "randIndex:" << randIndex <<  "| " << "shiftCount" << shiftCount << endl;
      // cout << "Shifting " << num << " to " << (direction ? "left" : "right") << " by " << shiftCount << " times " << endl;
    }
  }
}
