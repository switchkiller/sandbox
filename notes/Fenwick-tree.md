Fenwick tree is a very useful datastructure to perform range queries.

O<f(n), g(n) > is TC-0<nlogn, logn> space- 0(n) for BIT

Better than segment tree as requires less space.

Tricks
----

// O(1) operation
Finding the parent:

Take the 2's complement of the node.
Then and the resulting bits to the original binary number.
And finally add its result again with the original number to get parent node index.
