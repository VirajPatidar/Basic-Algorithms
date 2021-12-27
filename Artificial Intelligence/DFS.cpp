#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adj = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest)
{
    adj[src].push_back(dest);
}

void print(list<int> q)
{
    while (!q.empty())
    {
        cout << " " << q.front();
        q.pop_front();
    }
    cout << endl;
}

void printStack(stack<int> s)
{
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    cout << x << ' ';
    printStack(s);
    s.push(x);
}

void Graph::DFS(int s)
{
    vector<bool> visited(numVertices, false);
    stack<int> stack;
    stack.push(s);

    list<int> visited_nodes;
    int c = 0, p;

    while (!stack.empty())
    {
        int s = stack.top();
        stack.pop();

        if (!visited[s])
        {
            c++;
            cout << "\nITERATION: " << c << "\n";
            cout << "Visited: ";
            visited_nodes.push_back(s);
            print(visited_nodes);
            visited[s] = true;
        }

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);

        cout << "Fringe (Stack): ";
        printStack(stack);
        cout << "\n";
    }

    cout << "\nFINAL PATH: ";
    print(visited_nodes);

}

int main()
{
    Graph g(5);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.DFS(0);

    return 0;
}
