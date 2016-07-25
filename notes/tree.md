Tree is very important and useful data structure. A tree is an connected-acyclic graph. There are many many types of trees.

They are

- Weighted trees
- Rooted trees
- Directed trees
- Tries


Types of Binary Trees are:

1. Full Binary Tree - if node has either 0 or 2 child
2. Complete Binary Tree - if all levels are completely filled except for last level
3. Perfect Binary Tree - if all leaves are at the same level and each node has exactly two children
4. Balanced Binary Tree - if height of the tree is O(logn)
5. Degenerate Tree - Every node has exactly one child


Deletion of node in a BST:

Can be done by finding the inorder successor or by inorder predecessor.
Important thing to notice is, inorder successor is needed only when right child is not empty.
In this particular case, inorder successor can be obtained by finding the minimum value of right child of the node.
