#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T>

class Graph
{
    unordered_map<T, vector<T>> adj;

public:
    void addNode(T u, T v, bool directed)
    {
        // 0 -> undirected
        // 1 -> directed

        adj[u].push_back(v);
        if (!directed)
        {
            adj[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (int j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;

    int nodes;
    cout << "Enter the number of nodes : ";
    cin >> nodes;

    int edges;
    cout << "Enter the number of edges : ";
    cin >> edges;

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addNode(u, v, false);
    }

    g.printGraph();
    return 0;
}