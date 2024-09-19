# Binary Tree
* Binary Tree is a non-linear data structure where each node has at most two children.
* which may have zero,one or two but not more than two children.

# Representation of Binary Tree
Each node in a Binary Tree has three parts:
* Data
* Pointer to the left child
* Pointer to the right child


# Terminologies in Binary Tree
* `Nodes:` The fundamental part of a binary tree, where each node contains data and link to two child nodes.
* `Root:` The topmost node in a tree is known as the root node. It has no parent and serves as the starting point for all nodes in the tree.
* `Parent Node:` A node that has one or more child nodes. In a binary tree, each node can have at most two children.
* `Child Node:` A node that is a descendant of another node (its parent).
* `Leaf Node:` A node that does not have any children.
* `Internal Node:` A node that has at least one child. This includes all nodes except the root and the leaf nodes.
* `Depth of a Binary Tree:` The number of edges from a specific node to the root node. The depth of the root node is zero.
* `Height of a Binary Tree:` The number of nodes from the deepest leaf node to the root node.

# Properties of Binary Tree
* The maximum number of nodes at level L of a binary tree is 2^L
* The maximum number of nodes in a binary tree of height H is 2^H+1 – 1
* The minimum number of nodes in a binary tree of height H is H+1.

# Maximum Height:
The maximum height of a binary tree occurs when the tree is completely unbalanced, meaning each node has only one child (similar to a linked list).
In this case, the tree has a height of 𝑛−1
* Maximum Height: Height=𝑛−1.

# Minimum Height:
The minimum height of a binary tree occurs when the tree is perfectly balanced, meaning all levels are completely filled except possibly the last one.
The minimum height is given by 
⌈log2(𝑛+1)⌉−1.
* Minimum Height: Height=⌈log2(𝑛+1)⌉−1

# Types of BInary Tree:
* full/proper/strict
* complete binary tree
* perfect binary tree
* degenate binary tree

# Introduction to Complete Binary Tree
A binary tree is called complete binary tree when all the level of binary tree is completely filled except possibly the last level, which is filled from left side.

Difference between a complete binary tree and a full binary tree is that, in a complete binary tree all leaf nodes should lean towards left and the last nodes need not to have a right sibling.

