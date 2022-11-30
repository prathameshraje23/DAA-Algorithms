//kruskals algorithm




// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;
// DSU data structure
// path compression + rank by union
class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }
    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};
class Graph
{
    vector<vector<int>> edgelist;
    int V;

public:
    Graph(int V) { this->V = V; }
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({w, x, y});
    }
    void kruskals_mst()
    {
        // 1. Sort all edges
        sort(edgelist.begin(), edgelist.end());
        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << endl;
        for (auto edge : edgelist)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans += w;
                cout << x << " -- " << y << " == " << w << endl;
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans;
    }
};
// Driver's code
int main()
{
    Graph g(10);
    g.addEdge(0, 1, 15);
    g.addEdge(0, 2, 10);
    g.addEdge(0, 3, 19);
    g.addEdge(1, 3, 7);
    g.addEdge(1, 4, 17);
    g.addEdge(2, 3, 16);
    g.addEdge(2, 5, 14);
    g.addEdge(3, 4, 12);
    g.addEdge(3, 5, 6);
    g.addEdge(3, 6, 3);
    g.addEdge(4, 7, 13);
    g.addEdge(4, 6, 20);
    g.addEdge(5, 6, 9);
    g.addEdge(5, 8, 5);
    g.addEdge(6, 7, 4);
    g.addEdge(6, 9, 11);
    g.addEdge(6, 8, 1);
    g.addEdge(7, 9, 2);
    g.addEdge(8, 9, 18);
    // Function call
    g.kruskals_mst();
    return 0;
}














//Implement Kruskal’s algorithm & Prim's algorithm to find Minimum
//Spanning Tree (MST) of the given an undirected, connected and
//weighted graph.

//1) How many edges does a minimum spanning tree for above example?
//Ans. Every spanning tree of graph G(V,E) must contain V-1 edges where V is
//the number of vertices in the graph and E is the number of edges in the graph. In
//above graph total 10 vertices are present so minimum spanning tree of above
//graph will contain 10-1 that is 9 edges.

//2) In a graph G. let the edge u v have the least weight. is it true that u v is
//always part of any minimum spanning tree of G?.Justify your answers.
//Ans. Let a graph be G, and let it have V vertices and E edges.

//1. Now suppose you are able to manage a Minimum Spanning Tree T, such
//that the edge(u,v) is not included in T. (edge(u,v) is the least weighted edge).

//2. Now, the MST has V-1 edges and has no cycles. Now add the edge (u,v)
//to your MST.

//3. Now you will notice that one cycle forms in T due to the addition of
//edge(u,v). The cycle includes edge(u,v) and other edges which are part of T.

//4. In this cycle, select an edge whose weight is highest, it certainly will not
//be edge(u,v) because edge(u,v) has least weight. Hence you will select an edge
//from your earlier Minimum Spanning Tree T. Let this edge be E1.

//5. Now, remove E1 from T and add edge(u,v). Let this tree be called T_min.

//6. When we removed one edge from the cycle, connectivity of the new tree
//is still maintained.

//7. Also, as there are still V-1 edges so, there are no cycles in T_min. Hence
//T_min is a spanning tree. We still need to prove T_min as minimum spanning
//tree in order to prove.

//8. Weight ( T_min ) = Weight( T ) - (E1 - edge(u,v)).

//9. (E1 - edge(u,v)) is a positive entity as the question has already specified
//edge(u,v) to be minimum.

//10. Thus Weight (T_min) < Weight (T) , hence T can not be a minimum
//spanning tree. T_min is the minimum spanning tree which has edge(u,v).

//11. Thus, it is true that u v is always part of any minimum spanning tree of G.


//3) Let G be a graph and T be a minimum spanning tree of G. Suppose that
//the weight of an edge e is decreased. How can you find the minimum spanning
//tree of the modified graph? What is the runtime of your solution?
//Ans. This should be done in O(n) time. Given G be graph with n vertices and T
//be an minimum cost spanning tree and e be an edge not in T whose weight is
//decreased. We don't need to create MST again.

//1. Using DFS find the simple path for edge e in T. Cycle is guaranteed
//because MST has n-1 edges and an extra edge will obviously form a cycle.

//2. Find an edge weight w on that unique path which is maximum among all
//edge weight.

//3. Now check if weight of w is greater than that of e, then replace w in T
//with edge e.

//4. It'll take O(No. of Vertices) time because in worst case all vertices could
//be present in cycle and here n represents total vertices O(n).
//This can be done in linear time.

//4) Find order of edges for Kruskal's and Prim's?