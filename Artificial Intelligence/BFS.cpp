#include <iostream>
#include <list>

using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int src, int dest);
    void BFS(int startVertex);
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void printQueue(list<int> q)
{
	while (!q.empty()){
		cout<<" "<<q.front();
		q.pop_front();
	}
	cout<<endl;
}

void Graph::BFS(int startVertex)
{
    visited = new bool[numVertices];
    for (int i = 0; i < numVertices; i++)
        visited[i] = false;

    list<int> queue;
    list<int> visited_queue;

    visited[startVertex] = true;
    queue.push_back(startVertex);

    list<int>::iterator i;

    int c=0;

    while (!queue.empty())
    {
        int currVertex = queue.front();

        c++;
        cout << "ITERATION: " << c << "\n";
        cout << "Visited: ";
        visited_queue.push_back(currVertex);
        printQueue(visited_queue);


        queue.pop_front();

        for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
        {
            int adjVertex = *i;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
        }


        cout << "Fringe (Queue): ";
        printQueue(queue);
        cout << "\n";
    }
    cout << "FINAL PATH: ";
    printQueue(visited_queue);
}

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    g.BFS(0);

    return 0;
}