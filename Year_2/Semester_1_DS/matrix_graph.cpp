#include <iostream>
#include <vector>

using namespace std;

void create_adjacency_matrix(int N, int M, const vector<pair<int, int>>& edges) {

    vector<vector<int>> adjacency_matrix(N, vector<int>(N, 0));
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjacency_matrix[u - 1][v - 1] = 1;
        adjacency_matrix[v - 1][u - 1] = 1;
    }

    for (const auto& row : adjacency_matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    create_adjacency_matrix(N, M, edges);
    
    return 0;
}
