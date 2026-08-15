#include <iostream>
#include <climits>
using namespace std;

#define V 6

int getMinDistance(int dist[], bool visited[])
{
    int minDist = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < minDist)
        {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int graph[V][V], int source)
{
    int dist[V];
    int parent[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = getMinDistance(dist, visited);

        visited[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Shortest distance from A to F: "
         << dist[5] << " minutes" << endl;

    // Print route
    int path[V];
    int count = 0;

    int current = 5;

    while (current != -1)
    {
        path[count++] = current;
        current = parent[current];
    }

    cout << "Shortest Route: ";

    for (int i = count - 1; i >= 0; i--)
    {
        cout << char('A' + path[i]);

        if (i != 0)
            cout << " -> ";
    }

    cout << endl;
}

int main()
{
    int graph[V][V] = {0};

    // A = 0
    // B = 1
    // C = 2
    // D = 3
    // E = 4
    // F = 5

    graph[0][1] = 4; // A-B
    graph[1][0] = 4;

    graph[0][2] = 2; // A-C
    graph[2][0] = 2;

    graph[1][3] = 5; // B-D
    graph[3][1] = 5;

    graph[2][3] = 1; // C-D
    graph[3][2] = 1;

    graph[2][4] = 7; // C-E
    graph[4][2] = 7;

    graph[3][4] = 3; // D-E
    graph[4][3] = 3;

    graph[3][5] = 6; // D-F
    graph[5][3] = 6;

    graph[4][5] = 2; // E-F
    graph[5][4] = 2;

    dijkstra(graph, 0);

    return 0;
}