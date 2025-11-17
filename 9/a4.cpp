#include <iostream>
using namespace std;

// DFS to mark the whole island
void dfs(int r, int c, vector<vector<char>> &grid, int rows, int cols) {
    // boundary check or if cell is water or already visited
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
        return;
    }

    grid[r][c] = '0'; // mark visited by converting to water

    // explore all 4 directions
    dfs(r + 1, c, grid, rows, cols);
    dfs(r - 1, c, grid, rows, cols);
    dfs(r, c + 1, grid, rows, cols);
    dfs(r, c - 1, grid, rows, cols);
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<char>> grid(M, vector<char>(N));

    // input grid
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int islands = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            if (grid[i][j] == '1') {
                islands++;         // found a new island
                dfs(i, j, grid, M, N); // mark whole island
            }
        }
    }

    cout << islands;
    return 0;
}
