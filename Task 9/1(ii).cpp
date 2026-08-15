#include <iostream>
#include <queue>
using namespace std;

#define V 6

void BFS(int graph[V][V], int start)
{
    bool visited[V] = {false};

    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Exploration Order: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << char('A' + current) << " ";

        for (int i = 0; i < V; i++)
        {
            if (graph[current][i] != 0 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
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

    graph[0][1] = 1; // A-B
    graph[1][0] = 1;

    graph[0][2] = 1; // A-C
    graph[2][0] = 1;

    graph[1][3] = 1; // B-D
    graph[3][1] = 1;

    graph[2][3] = 1; // C-D
    graph[3][2] = 1;

    graph[2][4] = 1; // C-E
    graph[4][2] = 1;

    graph[3][4] = 1; // D-E
    graph[4][3] = 1;

    graph[3][5] = 1; // D-F
    graph[5][3] = 1;

    graph[4][5] = 1; // E-F
    graph[5][4] = 1;

    BFS(graph, 0);

    return 0;
}