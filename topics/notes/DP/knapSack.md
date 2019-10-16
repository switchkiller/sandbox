Okay, we are going to discuss on 0 1 Knapsack problem. It is a classical DP challenge.

I assume you already know about our problem statement.

There is a simple ####greedy approach you can give to this problem:

Take the ratio of value to weight (if +ve integer) consider it until our Knapsack capacity gets over. I can give an easy intuition with what I mean. Whatsoever, greedy approach is quite easy but is not completely satisfiable. Hence, there exists cases in which this approach will fail i.e this approach is not optimal. However, it can be used to solve the fractional knapsack problem. 

Hence we use DP to solve this problem.

What is our subproblem?

-> Simple - Choose i such that it has maximum value and minimum weight according to the given weight.
