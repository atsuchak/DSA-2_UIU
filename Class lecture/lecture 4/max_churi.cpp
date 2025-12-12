#include <bits/stdc++.h>
using namespace std;

int n;
int value[1000], memo[1000][1000];

int maxChuri(int i) {
    if(i >= n) return 0;
    if(memo != -1) return memo[i];
    
    memo[i] = max(value[i] + maxChuri(i+2), maxChuri(i+1));
    return memo[i];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i = 0; i < n; i++) cin >> value[i];

    memset(memo, -1, sizeof(memo));
    cout << maxChuri(0) << endl;

    return 0;
}