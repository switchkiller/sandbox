Time taken to build segment tree - O(N)
Space Complexity - O(N)

Time taken for RMQ - O(logN)

If array length is power of 2 then the array length will be (2n-1) and if the the length of the array is not power of 2, then look for just next number, which is power of 2 closer to n such that it is greater than n i.e m, thus the array length will be (2m-1)

Represent the segtree in new array. Build the tree accordingly. (Refer notes for tree diagram)

There are three things you will need to consider.
They are:

1. Partial Overlap
2. Total Overlap
3. No Overlap

Incase of partial overlap look for the left and right of the root node.

Incase of total overlap look return the value of the root node (or that node) It is the minimum range query.

Incase of no overlap, return a max (large number) from and backtrack to previous (parent) node.

Reference: http://letuskode.blogspot.in/2013/01/segtrees.html
https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/
