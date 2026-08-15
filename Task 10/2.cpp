#include <iostream>
using namespace std;

#define MAX 100
#define INF 99999

int main()
{
    int n, e;
    cin >> n >> e;

    int graph[MAX][MAX];

    // Initialize graph
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }

    // Input roads
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    // Floyd-Warshall
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] != INF &&
                    graph[k][j] != INF)
                {
                    if (graph[i][k] + graph[k][j] < graph[i][j])
                    {
                        graph[i][j] =
                            graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }

    // Headquarters
    int source;
    cin >> source;

    cout << "Minimum travel times from headquarters:" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << "City " << i << ": ";

        if (graph[source][i] == INF)
            cout << "INF";
        else
            cout << graph[source][i];

        cout << endl;
    }

    // Queries
    int q;
    cin >> q;

    cout << "\nQuery Answers:" << endl;

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;

        cout << a << " " << b << " -> ";

        if (graph[a][b] == INF)
            cout << "INF";
        else
            cout << graph[a][b];

        cout << endl;
    }

    return 0;
}