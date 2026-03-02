#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buildMatrix(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        matrix[u][v] = 1; // Mark the edge u-v
        matrix[v][u] = 1; // Mark the edge v-u for undirected graph
    }
    
    return matrix;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    vector<vector<int>> adjacencyMatrix = buildMatrix(n, edges);

    for (const auto& row : adjacencyMatrix) {
        for (size_t j = 0; j < row.size(); ++j) {
            cout << row[j];
            if (j < row.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
