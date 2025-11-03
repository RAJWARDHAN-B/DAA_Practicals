#include <iostream>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

// Helper function to reconstruct path
vector<int> getPath(int v, vector<int> &parent)
{
    vector<int> path;
    while (v != -1)
    {
        path.insert(path.begin(), v + 1); // store as 1-based index
        v = parent[v];
    }
    return path;
}

// Bellman-Ford Algorithm
bool bellmanFord(int V, int E, vector<vector<int>> &edges, int src, vector<int> &dist, vector<int> &parent)
{
    const int INF = INT_MAX;
    dist.assign(V, INF);
    parent.assign(V, -1);

    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }

    // Check for negative weight cycle
    for (auto &e : edges)
    {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            return false; // negative cycle found
        }
    }
    return true;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    vector<int> dist, parent;
    if (bellmanFord(V, E, edges, src, dist, parent))
    {
        cout << "\nVertex Distance and Path from Source:\n";
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << (i + 1) << " : ";
            if (dist[i] == INT_MAX)
            {
                cout << "INF\n";
            }
            else
            {
                cout << dist[i] << " , Path: ";
                vector<int> path = getPath(i, parent);
                for (int j = 0; j < path.size(); j++)
                {
                    cout << path[j];
                    if (j != path.size() - 1)
                        cout << " -> ";
                }
                cout << "\n";
            }
        }
    }
    else
    {
        cout << "Graph contains a negative weight cycle\n";
    }

    return 0;
}
