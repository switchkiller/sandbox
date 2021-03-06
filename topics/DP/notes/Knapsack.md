The 0-1 Knapsack Problem

The difference between this problem and the fractional one is that you can't take a fraction of an item. You either take the whole thing or none of it. So here, is the problem formally described:

Your goal is to maximize the value of  a knapsack that can hold at most W units worth of goods from a list of items I0,  I1,  ... In-1. Each item has two attributes:

1) Value - let this be vi for item Ii.
2) Weight - let this be wi for item Ii.

Now, instead of being able to take a certain weight of an item, you can only either take the item or not take the item.

The naive way to solve this problem is to cycle through all 2n subsets of the n items and pick the subset with a legal weight that maximizes the value of the knapsack. But, we can find a dynamic programming algorithm that will USUALLY do better than this brute force technique.

Our first attempt might be to characterize a sub-problem as follows:

Let Sk be the optimal subset of elements from {I0, I1,... Ik}. But what we find is that the optimal subset from the elements {I0, I1,... Ik+1} may not correspond to the optimal subset of elements from {I0, I1,... Ik} in any regular pattern. Basically, the solution to the optimization problem for Sk+1 might NOT contain the optimal solution from problem Sk.


To illustrate this, consider the following example:

Item		Weight		Value
I0		      3			10
I1		      8			4
I2		      9			9
I3		      8			11

The maximum weight the knapsack can hold is 20.

The best set of items from {I0, I1, I2} is {I0, I1, I2}  but the best set of items from {I0, I1, I2, I3}  is {I0, I2, I3}. In this example, note that this optimal solution, {I0, I2, I3}, does NOT build upon the previous optimal solution, {I0, I1, I2}. (I­nstead it build's upon the solution, {I0, I2}, which is really the optimal subset of   {I0, I1, I2}  with weight 12 or less.)

So, now, we must rework our example. In particular, after trial and error we may come up with the following idea:

Let B[k, w] represent the maximum total value of a subset Sk with weight w. Our goal is to find B[n, W], where n is the total number of items and W is the maximal weight the knapsack can carry.

Using this definition, we have B[0, w] = w0, if w >= w0.
						         = 0, otherwise

Now, we can derive the following relationship that B[k, w] obeys:

    B[k, w] = B[k - 1,w], if wk > w
    	    = max { B[k - 1,w], B[k - 1,w - wk] + vk}



In English, here is what this is saying:

1) The maximum value of a knapsack with a subset of items from {I0, I1, ... Ik} with weight w is the same as the maximum value of a knapsack with a subset of items from {I0, I1, ... Ik-1} with weight w, if item k weighs greater than w.

Basically, you can NOT increase the value of your knapsack with weight w if the new item you are considering weighs more than w – because it WON'T fit!!!

2) The maximum value of a knapsack with a subset of items from {I0, I1, ... Ik} with weight w could be the same as the maximum value of a knapsack with a subset of items from {I1, I2, ... Ik-1} with weight w, if item k should not be added into the knapsack.

OR

3) The maximum value of a knapsack with a subset of items from {I0, I1, ... Ik} with weight w could be the same as the maximum value of a knapsack with a subset of items from {I0, I1, ... Ik-1} with weight w-wk, plus item k.

You need to compare the values of knapsacks in both case 2 and 3 and take the maximal one.

Recursively, we will STILL have an O(2n) algorithm. But, using dynamic programming, we simply have to do a double loop - one loop running n times and the other loop running W times.



Here is a dynamic programming algorithm to solve the 0-1 Knapsack problem:

Input: S, a set of n items as described earlier, W the total weight of the knapsack. (Assume that the weights and values are stored in separate arrays named w and v, respectively.)

Output: The maximal value of items in a valid knapsack.

    int w, k;
    for (w=0; w <= W; w++)
         B[w] = 0

    for (k=0; k<n; k++) {

         for (w = W; w>= w[k]; w--)  {

              if (B[w – w[k]] + v[k] > B[w])
    	     B[w] = B[w – w[k]] + v[k]
         }
    }

Note on run time: Clearly the run time of this algorithm is O(nW), based on the nested loop structure and the simple operation inside of both loops. When comparing this with the previous O(2n), we find that depending on W, either the dynamic programming algorithm is more efficient or the brute force algorithm could be more efficient. (For example, for n=5, W=100000, brute force is preferable, but for n=30 and W=1000, the dynamic programming solution is preferable.)

Let's run through an example:
