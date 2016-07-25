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

Problems:

1. Check if the binary tree is a balanced binary tree.
   refer : miscellaneous/implementation/Gayle/Trees-and-Graphs/41.c

   #Important
   Notice that to be a balanced binary tree, the difference between subtree of a node cannot be greater than one.
   Okay now this solution is optimised solution. Whenever we encounter a node such that its not balanced we return -1.
   Otherwise we recursively calculate the heights and take the difference.


2. Check if route exists between two nodes.

    Use simple traversal like dfs or bfs.

3. Construct minimal height BST using a sorted array.

    Possible only when middle element chosen as root.
    Recursively divide the array, and decide the roots of left and right subarray.

    Build the root recursively.

4. Given a binary tree, design an algorithm which creates a LL of each depth.

    Solved using level order traversal. Can be solved using dfs too.
    refer: miscellaneous/implementation/Gayle/Trees-and-Graphs/44.cpp

5. Check if a binary tree is a binary search tree.

    #important
    
