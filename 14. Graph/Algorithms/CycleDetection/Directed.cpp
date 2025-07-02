#include <bits/stdc++.h>
using namespace std;

class DirectedGraph
{
    int V;
    vector<vector<int>> adj;

public:
    DirectedGraph(int v) : V(v)
    {
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool dfsUtil(int node, vector<bool> visited, vector<bool> recStack)
    {
        visited[node] = true;
        recStack[node] = true;

        for (int nbr : adj[node])
        {
            if (dfsUtil(nbr, visited, recStack))
            {
                return true;
            }
            else if (recStack[nbr])
            {
                return true;
            }
        }
        recStack[node] = false;
        return false;
    }

    bool detectCycleDFS()
    {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false); // Recursion Stack

        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dfsUtil(i, visited, recStack))
            {
                return true;
            }
        }
        return false;
    }

    bool detectCycleKahns()
    {
        vector<int>  inDegree(V, 0);
        for(int i = 0 ; i < V ; i++){
            for(int nbr : adj[i]){
                inDegree[nbr]++;
            }
        }

        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()){
            int node =  q.front();
            q.pop();
            count++;

            for(int nbr : adj[node]){
                if(--inDegree[nbr] == 0){
                    q.push(nbr);
                }
            }

        }

        return count != V;
    }
};

int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    DirectedGraph g(V);
    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int choice;
    cout << "\n1. Detect cycle using DFS\n2. Detect cycle using Kahn's Algo\nEnter choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << (g.detectCycleDFS() ? "Cycle Detected (DFS)" : "No Cycle (DFS)") << endl;
        break;
    case 2:
        cout << (g.detectCycleKahns() ? "Cycle Detected (Kahn's Algo)" : "No Cycle (Kahn's Algo)") << endl;
        break;
    default:
        cout << "Invalid Choice\n";
    }

    return 0;
}