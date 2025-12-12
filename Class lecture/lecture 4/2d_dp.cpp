#include <bits/stdc++.h>
using namespace std;

int m, n;
int grid[1000][1000], memo[1000][1000];

int maxPath(int i, int j) {
    if(i == m-1 && j == n-1) return grid[i][j];
    if(i == m && j == n) return 0;  //outside of the grid

    if(memo[i][j] != -1) return memo[i][j];

    memo[i][j] = max(maxPath(i+1, j), maxPath(i, j+1)) + grid[i][j];
    return memo[i][j];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> m >> n;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) cin >> grid[i][j];

    memset(memo, -1, sizeof(memo));
    cout << maxPath(0, 0) << endl;

    return 0;
}