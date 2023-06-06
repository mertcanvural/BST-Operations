# cs240-spring2023-cp4-mertcanvural
# April 2023

# Project Description

This C++ project aims to investigate the impact of tree balance on the number of operations required to perform various binary tree operations. The project builds different types of trees, including both balanced and unbalanced ones, and measures the number of comparisons needed to complete each operation.

To test this hypothesis, a vector consisting of a certain number of elements is used to insert nodes into the tree. The vector is then shuffled or shaken by a certain amount to observe how it affects the tree's structure. Additionally, the vector size is modified to measure how the operation counts change as the number of tree nodes grows.

The main hypothesis is that balanced trees tend to require fewer comparisons compared to unbalanced trees. This hypothesis is based on the principle that balanced trees maintain a more even distribution of elements, leading to shorter search paths and quicker retrieval of data.

The project employs various tree-building algorithms and implements common binary tree operations such as insertion, deletion, and searching. The number of comparisons made during the operation is recorded.

By analyzing the collected data, the project aims to provide empirical evidence supporting the hypothesis that balanced trees exhibit superior performance in terms of reducing the number of comparisons required for common operations. This knowledge can contribute to a better understanding and decision-making when designing and implementing tree-based data structures in various applications.
