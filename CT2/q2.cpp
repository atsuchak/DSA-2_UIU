#include<bits/stdc++.h>
using namespace std;

int n, x;
vector<int> coins;
int memo[1000];

int mnCoin(int n) {
    if(n == 0) return 0;
    if(n < 0) return INT_MAX;
    if(memo[n] != -1) return memo[n];

    int mn = INT_MAX;
    for(auto it : coins) {
        int str = mnCoin(n - it);
        if(str < mn) mn = str;
    }

    return memo[n] = mn+1;
}

int main() {
    memset(memo, -1, sizeof(memo));

    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        coins.push_back(c);
    }

    (mnCoin(x) < -1)? cout << -1 << endl : cout << mnCoin(x) << endl;

    return 0;
}


/*
3 11
1 5 7

3 3
2 4 6
*/