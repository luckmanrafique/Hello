#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, w;
};

Edge edges[MAX];
int parent[MAX];

// Find function for Kruskal
int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

// Sort edges by weight
bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

// Prim's Algorithm
void prim(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    selected[0] = 1;

    int edgeCount = 0, total = 0;

    cout << "\nPrim's MST:\n";

    while (edgeCount < n - 1) {
        int min = 9999;
        int x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j] != 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << min << endl;
        total += min;
        selected[y] = 1;
        edgeCount++;
    }

    cout << "Total Cost = " << total << endl;
}

// Kruskal's Algorithm
void kruskal(int n, int m) {
    sort(edges, edges + m, compare);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;

    cout << "\nKruskal's MST:\n";

    for (int i = 0; i < m; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            cout << edges[i].u << " - " << edges[i].v
                 << " : " << edges[i].w << endl;

            total += edges[i].w;
            parent[a] = b;
        }
    }

    cout << "Total Cost = " << total << endl;
}

int main() {
    int n, m;
    int graph[MAX][MAX] = {0};

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter (u v weight):\n";

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

        graph[edges[i].u][edges[i].v] = edges[i].w;
        graph[edges[i].v][edges[i].u] = edges[i].w;
    }

    prim(graph, n);
    kruskal(n, m);

    return 0;
}