#DFS - Depth First Search

Everyone loves graph theory. Because of its sweet simplicity and sour complexity.

Today I would love to share my thoughts on DFS.

####* Its more like recursive backtracking but clever!

I would not discuss the complete algorithm the boring way. I will go our code way, ahah :)

#####Note: DFS is used for connected components.

###But what makes DFS different then the recursive backtracking???

The answer is, there we mark some nodes visited and some not visited.

It might sound like, how, whhaat, errr. But wait.... I am explaining

Actually, dfs is very simple method of traversal.

What we do is, we mark a `int dfs_num[V]` which will contain the information if the node has been visited or not.

BUT HOW??

 *  You will take a arbitary node, or vertex from the user.  This is the starter node (vertex). Its from where the traversal will actually begin!

 *  This vertex, (starter vertex) will be marked visited.

 *  The vertex adjacent to it are checked, The idea is to take all the adjacent vertex into the stack, the one at the top of the stack is process, marked as visited and so on. We will get it through my code soon.

 *  Again recursively, the vertex adjacent to the nearby vertex is taken into stack-frame.

        void dfs(int u){  //You took an element u to begin the traversal
          dfs_num[u] = DFS_BLACK; //We mark the visited node BLACK.
          TRvii (AdjList[u], v) //v is an iterator pointing to ii, where as AdjList is of a vector.
            if (dfs_num[v->first] == DFS_WHITE) //Self-explanatory
              dfs(v->first);
        } //where v->first is the neighbor of vertex and v->second is the weight of the edge.

  Using STL for solving graphs is very convenient method.

  ###Finding the connected components.

  Dfs is not only useful for traversal. Its much more.

  Lets take a code to go through.

        //inside func()
        numComponent = 0;
        REP(i,0,V-1){
          if (dfs_num[i] == DFS_WHITE)
            printf("Connected component %d :",++numComponent)
            dfs(i);
        }

------------
##Finding the Articulation Point and Bridges:

Let me tell you, this problem is one of most interesting to me. You are given a road map which is undirected. It has many intersections as vertices and edges. Now you have create a sabotage. Yea,.. SABOTAGE, that has the minimum cost such that the road network breaks down. This problem is about finding the least cost articulation point (intersection) or the least cost bridge (road) in an undirected graph. (road-map.)

An articulation point is defined as a vertex in a graph G whose removal disconnects G. A graph without such point is called 'biconnected'.

Suppose, you are a vandal seeking to disrupt the telephone network. Which station in should you choose to blow up to cause the maximum amount of damage? Observe that there is a single point of failure, a single vertex whose deletion disconnects a connected componenets of the graph. Such a vertex is called articulation vertex or cut node.Deleting it causes a loss of connectivity between other nodes.

 
