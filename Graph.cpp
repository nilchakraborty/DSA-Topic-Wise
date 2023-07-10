/*👉🏻 Graph Representation :
Nodes: represent points in a graph
Edges: represent the connections or relationships between those points
Directed Graph: A directed graph is a graph in which all the edges are unidirectional. This means that the edges only go one way. For example, if there is an edge from node 1 to node 2, there is no edge from node 2 to node 1.
Undirected Graph: An undirected graph is a graph in which all the edges are bidirectional. This means that the edges can go both ways. For example, if there is an edge from node 1 to node 2, there is also an edge from node 2 to node 1.
Weighted Graph: A weighted graph is a graph in which each edge is assigned a weight or cost. For example, if the edges of a graph represent cities and the weight represents the distance between the cities, then a weighted edge means that there is a cost or distance associated with traveling from one city to another.
Adjacency Matrix: An adjacency matrix is a matrix representation of a graph. In an adjacency matrix, the rows represent source vertices and columns represent destination vertices. The value that is stored in the cell at the intersection of row v and column w indicates if there is an edge from vertex v to vertex w. If there is an edge, the value is 1, otherwise, the value is 0.
Adjacency List: An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph. For example, if there are three vertices in a graph, say 0, 1 and 2, then the adjacency list for vertex 0 would be a list containing the vertices 1 and 2.
Indegree: The indegree of a vertex is the number of edges that are directed towards it.
Outdegree: The outdegree of a vertex is the number of edges that are directed away from it.

👉🏻 Adjacency Matrix
int adj[n+1][n+1];
for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1;
    adj[v][u] = 1;
}

👉🏻 Adjacency Lists (undirected graph)
vector<int> adj[n+1];
for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

👉🏻 Adjacency Lists (directed graph)
vector<int> adj[n+1];
for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
}

👉🏻 Graph Traversal:
for(int i = 0; i < n; i++)
    if(!visited[i])
        traversal(i);

👉🏻 take input : int dy[4] = {0, -1, 0, 1};
int dx[4] = { -1, 0, 1, 0};
for (int k = 0; k < 4; k++){
int newy = r + dy[k];
int newx = c + dx[k];
DFS(board, newy, newx, rsize, csize);}
is way better than taking 4 input and run same func 4times like :
DFS(board, r + 1, c, rsize, csize);
DFS(board, r, c + 1, rsize, csize);
DFS(board, r - 1, c, rsize, csize);
DFS(board, r, c - 1, rsize, csize);*/
/*// Breadth First Search
// Time Complexity: O(N) + O(2E)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0); // push the initial starting node 
        vector<int> bfs; 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            bfs.push_back(node); 
            for(auto it : adj[node]) {// traverse for all its neighbours 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    vector <int> adj[6];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);
    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);
    return 0;
}*/
/*// Depth First Search
#include <bits/stdc++.h>
using namespace std;
class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        int start = 0;
        vector<int> ls; // create a list to store dfs
        dfs(start, adj, vis, ls); // call dfs for starting node
        return ls; 
    }
};
void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
int main() {
    vector <int> adj[5];
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    Solution obj;
    vector <int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);
    return 0;
}*/
// Problems on BFS/DFS
/*// Number of Provinces
// Time Complexity: O(N) + O(V+2E)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  private:
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V];
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            if(!vis[i]) {
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
    }
};
int main() { 
    vector<vector<int>> adj{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };   
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
    return 0;
}*/
/*// Number of connected components
#define maxRow 500
#define maxCol 500
bool visited[maxRow][maxCol] = { 0 };
bool isSafe(string M[], int row, int col, char c,int n, int l){
    return (row >= 0 && row < n)
           && (col >= 0 && col < l)
           && (M[row][col] == c && !visited[row][col]);
}
// Function for depth first search
void DFS(string M[], int row, int col, char c,int n, int l){
    int colNbr[] = { 0, 0, 1, -1 };
    visited[row][col] = true;
    for (int k = 0; k < 4; ++k)
        if (isSafe(M, row + rowNbr[k],
                  col + colNbr[k], c, n, l))
 
            DFS(M, row + rowNbr[k],
                col + colNbr[k], c, n, l);
}
int connectedComponents(string M[], int n){
    int connectedComp = 0;
    int l = M[0].length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            if (!visited[i][j]) {
                char c = M[i][j];
                DFS(M, i, j, c, n, l);
                connectedComp++;
            }
        }
    }
    return connectedComp;
}*/
/*// Rotten Oranges
int orangesRotting(vector<vector<int>>& grid) {
    if(grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;
    queue<pair<int, int>> rotten;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] != 0) tot++;
            if(grid[i][j] == 2) rotten.push({i, j});
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while(!rotten.empty()){
        int k = rotten.size();
        cnt += k; 
        while(k--){
            int x = rotten.front().first, y = rotten.front().second;
            rotten.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != 1) continue;
                grid[nx][ny] = 2;
                rotten.push({nx, ny});
            }
        }
        if(!rotten.empty()) days++;
    }
    return tot == cnt ? days : -1;
}*/
/*// flood fill algo
void dfs(int row, int col, vector<vector<int>>&ans,
    vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
    int iniColor) {
    ans[row][col] = newColor; 
    int n = image.size();
    int m = image[0].size(); 
    for(int i = 0;i<4;i++) {
        int nrow = row + delRow[i]; 
        int ncol = col + delCol[i]; 
        if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
        image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
            dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, 
int sr, int sc, int newColor) {
    int iniColor = image[sr][sc]; 
    vector<vector<int>> ans = image; 
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1}; 
    dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
    return ans; 
}*/
/*// Detect cycle in an undirected graph(using BFS)
bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1; 
    queue<pair<int,int>> q; // store <source node, parent node>
    q.push({src, -1}); 
    while(!q.empty()) {
        int node = q.front().first; 
        int parent = q.front().second; 
        q.pop(); 
        for(auto adjacentNode: adj[node]) {
            if(!vis[adjacentNode]) {
                vis[adjacentNode] = 1; 
                q.push({adjacentNode, node}); 
            }
            else if(parent != adjacentNode) {
                return true; 
            }
        }
    }
    return false; 
}]
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for(int i = 0;i<V;i++) {
        if(!vis[i]) {
            if(detect(i, adj, vis)) return true; 
        }
    }
    return false; 
}*/
/*// Detect Cycle in an Undirected Graph(using DFS)
bool dfs(int node, int parent, int vis[], vector<int> adj[]) {
    vis[node] = 1;
    for(auto adjacentNode: adj[node]) {
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, vis, adj) == true) 
                return true; 
        }
        else if(adjacentNode != parent) return true; 
    }
    return false; 
}
bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    for(int i = 0;i<V;i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj) == true) return true; 
        }
    }
    return false; 
}*/
/*// Detect Cycle in a Directed Graph(using DFS)
bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis) == true)
                return true;
        }
        else if (pathVis[it]) {
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis) == true) return true;
        }
    }
    return false;
}*/
/*// 01 Matrix
vector<vector<int>> updateMatrix(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    int INF = m + n;
    for (int r = 0; r < n; r++){
        for (int c = 0; c < m; c++){
            int top = INF, left = INF;
            if (mat[r][c] == 0)
                continue;
            if (r >= 1)
                top = mat[r - 1][c];
            if (c >= 1)
                left = mat[r][c - 1];
            mat[r][c] = min(top, left) + 1;
        }
    }
    for (int r = n - 1; r >= 0; r--){
        for (int c = m - 1; c >= 0; c--){
            int bottom = INF, right = INF;
            if (mat[r][c] == 0)
                continue;
            if (r < n - 1)
                bottom = mat[r + 1][c];
            if (c < m - 1)
                right = mat[r][c + 1];
            mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
        }
    }
    return mat;
}*/
/*// Surrounded Regions
void solve(vector<vector<char>>& board) {
    if(board.empty()) return;
    int row = board.size(),col = board[0].size();
    for(int i=0;i<col;i++)DFS(board,0,i,row,col),DFS(board,row-1,i,row,col);
    for(int i=0;i<row;i++)DFS(board,i,0,row,col),DFS(board,i,col-1,row,col); 
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            if(board[i][j]=='O')board[i][j]='X';
            else if(board[i][j]=='P')board[i][j]='O';
}
void DFS(vector<vector<char>>& board,int r,int c,int rsize,int csize){
    if(r<0||c<0||r==rsize||c==csize||board[r][c]!='O')return;
    board[r][c] = 'P';
    int dx[4] = { -1, 0, 1, 0},dy[4] = {0, -1, 0, 1};
    for (int k = 0; k < 4; k++) { 
        int newx = c + dx[k], newy = r + dy[k];
        DFS(board, newy, newx, rsize, csize);
    }
}*/
/*// Number of Enclaves
void dfs(vector<vector<int>> &A, int i, int j){
    if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] == 0)
        return;
    A[i][j] = 0;
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = { -1, 0, 1, 0};
    for (int k = 0; k < 4; k++) {
    int newy = i + dy[k];
    int newx = j + dx[k];
    dfs(A, newy, newx);}
}
int numEnclaves(vector<vector<int>> &A){
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[0].size(); j++)
            if (i * j == 0 || i == A.size() - 1 || j == A[i].size() - 1)
                dfs(A, i, j);
    return accumulate(begin(A), end(A), 0, [](int s, vector<int> &r)
                        { return s + accumulate(begin(r), end(r), 0); });
}*/
/*// Number of Isalnds
void DFS(vector<vector<int>>& M, int i, int j, int ROW, int COL) {
    if (i < 0 || j < 0 || i >= ROW || j >= COL || M[i][j] != 1)
        return;
    M[i][j] = 0;
    int dy[4] = {0, -1, 0, 1};
    int dx[4] = {-1, 0, 1, 0};
    for (int k = 0; k < 4; k++) {
        int newy = i + dy[k];
        int newx = j + dx[k];
        DFS(M, newy, newx, ROW, COL);
    }
}
int countIslands(vector<vector<int>>& M) {
    int ROW = M.size();
    int COL = M[0].size();
    int count = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (M[i][j] == 1) {
                count++;
                DFS(M, i, j, ROW, COL);
            }
        }
    }
    return count;
}*/
/*// Is graph Bipartite
bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> color(n);
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (color[i])
            continue;
        color[i] = 1;
        for (q.push(i); !q.empty(); q.pop()){
            int cur = q.front();
            for (int neighbor : graph[cur]){
                if (!color[neighbor]){
                    color[neighbor] = -color[cur];
                    q.push(neighbor);
                }
                else if (color[neighbor] == color[cur])
                    return false;
            }
        }
    }
    return true;
}*/
// Topo Sort and Problems
/*// Topological Sort
// Time Complexity: O(V+E)+O(V)
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void dfs(int node, int vis[], stack<int> &st,
	         vector<int> adj[]) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}
public:
	vector<int> topoSort(int V, vector<int> adj[]){
		int vis[V] = {0};
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}
		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};
int main() {
	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);
	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;
	return 0;
}*/
/*// kahn's algo
vector<int> topoSort(int V, vector<int> adj[]){
    int indegree[V] = {0};
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }
    return topo;
}*/
/*// Course Schedule
bool iscycle(vector<int> adj[], vector<int> &vis, int id){
    if (vis[id] == 1)
        return true;
    if (vis[id] == 0){
        vis[id] = 1;
        for (auto edge: adj[id]){
            if (iscycle(adj, vis, edge))
                return true;
        }
    }
    vis[id] = 2;
    return false;
}
bool canFinish(int n, vector<vector < int>> &pre){
    vector<int> adj[n];
    for (auto edge: pre)
        adj[edge[1]].push_back(edge[0]);
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++){
        if (iscycle(adj, vis, i))
            return false;
    }
    return true;
}*/
/*// Find Eventual Safe States
bool dfs(vector<vector < int>> &graph, vector< int > &color, int node){
    color[node] = 1;
    for (auto cur: graph[node])
        if ((color[cur] == 0 && dfs(graph, color, cur)) || color[cur] == 1)
            return true;
    color[node] = 2;
    return false;
}
vector<int> eventualSafeNodes(vector<vector < int>> &graph){
    vector<int> color(graph.size()), result;
    for (int i = 0; i < graph.size(); i++)
        if (color[i] == 2 || !dfs(graph, color, i))
            result.push_back(i);
    return result;
}*/
/*// Alien Dictionary
https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26/*/
// Shortest Path Algorithms and Problems :
// Dijkstra's algorithm why we use priority_queue instead of queue cause priority queue is O((E+V)logV) and queue would be O(EV).
// Bellman-Ford is used for graphs with negative edge weights, while Floyd-Warshall is used for graphs without negative edge weights. 
// Bellman-Ford is a single-source algorithm, meaning it computes the shortest path from a single source, while Floyd-Warshall computes the shortest distances between every pair of vertices in the input graph. 
// To summarize, we use Floyd-Warshall for all pairs shortest path, Dijkstra for single source shortest path with non-negative weights, and Bellman-Ford for single source shortest path with negative weights and negative cycles. 
// In the Floyd-Warshall algorithm, the diagonal elements of the distance matrix are set to 0 because they represent the distance from a vertex to itself, which is always 0.
/*// Shortest Path in Undirected Graph with unit distance
https://takeuforward.org/data-structure/shortest-path-in-undirected-graph-with-unit-distance-g-28/*/
/*// Shortest Path in Directed Acyclic Graph
https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/*/
/*// Dijkstra’s Algorithm
https://takeuforward.org/data-structure/dijkstras-algorithm-using-priority-queue-g-32/ (using priority queue)
https://takeuforward.org/data-structure/dijkstras-algorithm-using-set-g-33/*/
/*// Bellman Ford Algorithm
https://takeuforward.org/data-structure/bellman-ford-algorithm-g-41/*/
/*// Floyd Warshall Algorithm
https://takeuforward.org/data-structure/floyd-warshall-algorithm-g-42/*/
/*// Shortest Path in Binary Matrix
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
        return -1;
    if (n == 1)
        return 1;
    queue<pair<int, int>> q;
    int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    int dist = 0;
    q.push({0, 0});
    grid[0][0] = 1;
    while (!q.empty())
    {
        int size = q.size();
        dist++;
        while (size--)
        {
            auto front = q.front();
            q.pop();
            for (auto d : dir)
            {
                int adI = front.first + d[0];
                int adJ = front.second + d[1];
                if (adI < 0 || adJ < 0 || adI >= n || adJ >= n)
                    continue;
                if (grid[adI][adJ] == 1)
                    continue;
                grid[adI][adJ] = 1;
                if (adI == n - 1 && adJ == n - 1)
                    return dist + 1;
                q.push({adI, adJ});
            }
        }
    }
    return -1;
}*/
/*// Path With Minimum Effort
int minimumEffortPath(vector<vector<int>> &heights){
    int M = heights.size(), N = heights[0].size();
    vector<vector<int>> path(M, vector<int>(N, INT_MAX));
    queue<pair<int, int>> Q;
    Q.push({0, 0}); 
    path[0][0] = 0;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!Q.empty()){
        pair<int, int> curr = Q.front();
        Q.pop();
        int i = curr.first, j = curr.second;
        for (auto d : dir){ 
            int ri = i + d[0], rj = j + d[1];
            if (ri >= 0 && ri < M && rj >= 0 && rj < N){
                int diff = abs(heights[i][j] - heights[ri][rj]);
                int maxval = max(path[i][j], diff);
                if (maxval < path[ri][rj]){ 
                    path[ri][rj] = maxval;
                    Q.push({ri, rj});
                }
            }
        }
    }
    return path[M - 1][N - 1];
}*/
/*// Cheapest Flights Within K Stops
int findCheapestPrice(int n, vector<vector<int>>& a, int src, int sink, int k) {    
    vector<int> c(n, 1e8);
    c[src] = 0;
    for(int z=0; z<=k; z++){
        vector<int> C(c);
        for(auto e: a)
            C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
        c = C;
    }
    return c[sink] == 1e8 ? -1 : c[sink];
}*/
/*// Minimum Multiplications to Reach End
int minimumMultiplications(vector<int> &arr,int start, int end){
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;
    while (!q.empty()){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        for (auto it : arr){
            int num = (it * node) % mod;
            if (steps + 1 < dist[num]){
                dist[num] = steps + 1;
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}*/
/*// Find the City With the Smallest Number of Neighbors at a Threshold Distance
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int dist[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = i == j ? 0 : 10001;
        }
    }
    for (auto &e : edges) {
        dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int res = -1, resCount = INT_MAX;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= distanceThreshold) {
                count++;
            }
        }
        if (count <= resCount) {
            resCount = count;
            res = i;
        }
    }
    return res;
}*/
// Minimum Spanning Tree / Disjoint Set and Problems
/*// Prim's Algorithm
https://takeuforward.org/data-structure/prims-algorithm-minimum-spanning-tree-c-and-java-g-45/*/
/*// Kruskal's Algorithm
https://takeuforward.org/data-structure/kruskals-algorithm-minimum-spanning-tree-g-47/*/
/*// Disjoint Set Union by Rank and by Size
https://takeuforward.org/data-structure/disjoint-set-union-by-rank-union-by-size-path-compression-g-46/*/
/*// Number of Operations to Make Network Connected
void dfs(vector<vector<int>> &adj,vector<bool> &visited,int n){
    visited[n]=true;
    for(auto i:adj[n])
        if(!visited[i])
            dfs(adj,visited,i);
}
int makeConnected(int n, vector<vector<int>>& a) {
    if(a.size()<n-1) return -1;
    vector<vector<int>> adj(n);
    for(auto v:a){
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<bool> visited(n,false);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(adj,visited,i);
            cnt++;
        }
    }
    return cnt-1;
}*/
/*// Most Stones Removed with Same Row or Column
int dfs(vector<vector<int>> &stones, int index, vector<bool> &visited, int &n){
    visited[index] = true;
    int result = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
            result += (dfs(stones, i, visited, n) + 1);
    return result;
}
int removeStones(vector<vector<int>> &stones){
    int n = stones.size();
    vector<bool> visited(n, 0);
    int result = 0;
    for (int i = 0; i < n; i++){
        if (visited[i]){
            continue;
        }
        result += dfs(stones, i, visited, n);
    }
    return result;
}*/
/*// Accounts Merge
https://takeuforward.org/data-structure/accounts-merge-dsu-g-50/*/
/*// Number of Islands – II – Online Queries
https://takeuforward.org/graph/number-of-islands-ii-online-queries-dsu-g-51/*/
/*// Making a Large Island
https://takeuforward.org/data-structure/making-a-large-island-dsu-g-52/*/
/*// Kosaraju’s Algorithm(Strongly Connected Components)
https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/*/
/*// Tarjan’s Algorithm (Bridges in Graph)
https://takeuforward.org/graph/bridges-in-graph-using-tarjans-algorithm-of-time-in-and-low-time-g-55/*/
/*// Articulation Point
https://takeuforward.org/data-structure/articulation-point-in-graph-g-56/*/

//TIME COMPLEXITY: O(V+E)
#include<bits/stdc++.h>
using namespace std;
#define V 7
#define pb push_back
unordered_map<int,vector<int>> adj;
void DFS(int u,vector<int>& disc,vector<int>& low,stack<int>& mystack,vector<bool>& presentInStack)
{
    static int time = 0;
    disc[u] = low[u] = time;
    time+=1;
    mystack.push(u);
    presentInStack[u] = true;
    for(int v: adj[u])
    {
        if(disc[v]==-1)	//If v is not visited
        {
            DFS(v,disc,low,mystack,presentInStack);
            low[u] = min(low[u],low[v]);
        }
        //Differentiate back-edge and cross-edge
        else if(presentInStack[v])	//Back-edge case
            low[u] = min(low[u],disc[v]);
    }
    if(low[u]==disc[u])	//If u is head node of SCC
    {
        cout<<"SCC is: ";
        while(mystack.top()!=u)
        {
            cout<<mystack.top()<<" ";
            presentInStack[mystack.top()] = false;
            mystack.pop();
        }
        cout<<mystack.top()<<"\n";
        presentInStack[mystack.top()] = false;
        mystack.pop();
    }
}
void findSCCs_Tarjan()
{
    vector<int> disc(V,-1),low(V,-1);
    vector<bool> presentInStack(V,false);	//Avoids cross-edge
    stack<int> mystack;
    for(int i=0;i<V;++i)
        if(disc[i]==-1)
            DFS(i,disc,low,mystack,presentInStack);
}
int main()
{
    adj[0].pb(1);
    adj[1].pb(2);
    adj[1].pb(3);
    adj[3].pb(4);
    adj[4].pb(0);
    adj[4].pb(5);
    adj[4].pb(6);
    adj[5].pb(6);
    adj[6].pb(5);
    findSCCs_Tarjan();
    return 0;
}*/