#include <iostream>
using namespace std;

int n;
int graph[100][100];
bool visited[100];

void DFS(int node) {
    visited[node] = true;

    cout << node << " ";

    // Check all possible neighbors
    for (int i = 1; i <= n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    // Initialize visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    int start = 1;

    cout << "DFS Traversal: ";

    DFS(start);

    cout << endl;

    return 0;
}