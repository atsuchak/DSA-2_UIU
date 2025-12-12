#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000], memo[1000];

int flags(int n) {
    if(n <= 2) return 1;
    if(memo[n] != -1) return memo[n];

    memo[n] = flags(n-1) + flags(n-2);
    return memo[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    memset(memo, -1, sizeof(memo));
    cout << flags(0) << endl;

    return 0;
}