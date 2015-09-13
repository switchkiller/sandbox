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
          dfs_num[u] = DFS_BLACK;
          TRvii (AdjList[u], v)
            if (dfs_num[v->first] == DFS_WHITE)
              dfs(v->first);
        } //where v->first is the neighbor of vertex and v->second is the weight of the edge.

  Using STL for solving graphs is very convenient method.  
    
