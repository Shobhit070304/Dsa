#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>

class Graph
{
    // unordered_map<T, vector<T>> adj;
    vector<vector<int>> adj;

public:
    Graph(int nodes)
    {
        adj.resize(nodes, vector<int>(nodes, 0));
    }
    // void addNode(T u, T v, bool directed)
    // {
    //     // 0 -> undirected
    //     // 1 -> directed

    //     adj[u].push_back(v);
    //     if (!directed)
    //     {
    //         adj[v].push_back(u);
    //     }
    // }

    void addNode(int u, int v, bool directed)
    {
        adj[u][v] = 1;
        if (!directed)
        {
            adj[v][u] = 1;
        }
    }

    // void printGraph()
    // {
    //     for (auto i : adj)
    //     {
    //         cout << i.first << "-> ";
    //         for (int j : i.second)
    //         {
    //             cout << j << ", ";
    //         }
    //         cout << endl;
    //     }
    // }

    void printGraph()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{

    int nodes;
    cout << "Enter the number of nodes : ";
    cin >> nodes;

    int edges;
    cout << "Enter the number of edges : ";
    cin >> edges;

    Graph<int> g(nodes);

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addNode(u, v, false);
    }

    g.printGraph();
    return 0;
}