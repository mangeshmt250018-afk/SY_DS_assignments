#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    
    vector<vector<int>> adj;

public:
    Graph(int v) {
        vertices = v;
       
        adj.resize(vertices + 1, vector<int>(vertices + 1, 0));
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    void BFS(int start) {
        vector<bool> visited(vertices + 1, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " "; 

            for (int i = 1; i <= vertices; i++) {
                if (adj[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    void DFSUtil(int current, vector<bool>& visited) {
        visited[current] = true;
        cout << current << " ";

        for (int i = 1; i <= vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(vertices + 1, false);
        cout << "DFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    g.BFS(start);
    g.DFS(start);

    return 0;
}
