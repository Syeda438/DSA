#include<iostream>
using namespace std;
const int MAX = 100;
class Graph {
    int V;
    int adj[MAX][MAX];
public:
    Graph(int v) {
        V = v;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v) {
        adj[u][v] = 1;
    }
    void printGraph() {
        cout << "\nAdjacency Matrix:\n";

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
        cout << "\nGraph (Edges):\n";
        for(int i = 0; i < V; i++) {
            cout << i << " -> ";
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1)
                    cout << j << " -> ";
            }
            cout << endl;
        }
    }
    void BFS(int start) {
        bool visited[MAX] = {false};
        int queue[MAX];
        int front = 0, rear = 0;
        cout << "\nBFS Traversal:\n";
        visited[start] = true;
        queue[rear++] = start;
        while(front < rear) {
            int node = queue[front++];
            cout << "Visiting: " << node << endl;
            for(int i = 0; i < V; i++) {
                if(adj[node][i] == 1 && !visited[i]) {
                    cout << "  Exploring edge " << node << " -> " << i << endl;
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
    }
    void DFSUtil(int node, bool visited[]) {
        visited[node] = true;
        cout << "Visiting: " << node << endl;
        for(int i = 0; i < V; i++) {
            if(adj[node][i] == 1 && !visited[i]) {
                cout << "  Exploring edge " << node << " -> " << i << endl;
                DFSUtil(i, visited);
            }
        }
    }
    void DFS(int start) {
        bool visited[MAX] = {false};
        cout << "\nDFS Traversal:\n";
        DFSUtil(start, visited);
    }
    bool isConnected(int start) {
        bool visited[MAX] = {false};
        int queue[MAX];
        int front = 0, rear = 0;
        visited[start] = true;
        queue[rear++] = start;
        int count = 0;
        while(front < rear) {
            int node = queue[front++];
            count++;
            for(int i = 0; i < V; i++) {
                if(adj[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }
        return (count == V);
    }
};
int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(1, 5);
    cout << "GRAPH STRUCTURE";
    g.printGraph();
    g.BFS(0);
    g.DFS(0);
    cout << "\nConnectivity Check:\n";
    if(g.isConnected(0))
        cout << "Graph is CONNECTED from node 0\n";
    else
        cout << "Graph is NOT FULLY CONNECTED from node 0\n";
    return 0;
}