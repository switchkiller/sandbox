There are two types of problems solvable by partial sum.
1.Problems which you are asked to answer some queries about the sum of a part of elements (without modify queries).
Solution of all of this problems are the same. You just need to know how to solve one of them.
Example : You are asked some queries on an array a1, a2, ...a, n. Each query give you numbers l and r and you should print al + al + 1 + ... + ar .
Solution : You need to build another array s1, s2, ..., sn which si = a1 + a2 + ... + ai and answer is sr - sl - 1 .
2.Problems which you are asked to perform some queries asking you to modify a part of elements (without printing queries.)
Solution of all of this problems are the same. You just need to know how to solve one of them.
Example : You need to perform some queries on an array a1, a2, ...a, n. Each query give you numbers l, r and v and for each i such that l ≤ i ≤ r you should increase ai by v, and then after performing all queries, you should print the whole array.
Solution : You should have another array p1, p2, ..., pn which, all of its members are initially 0, for each query, you should increase pl by v and decrease pr + 1 by v .
An then, for each i, starting from 1 you should increase pi by pi - 1. So, final array would be a1 + p1, a2 + p2, ..., an + pn .
