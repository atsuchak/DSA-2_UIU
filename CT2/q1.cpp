#include<bits/stdc++.h>
using namespace std;

int n;
int memo[1000];
vector<int> house(1000);

int rob(int x) {
    if(x > n) return 0;
    if(memo[x] != -1) return memo[x];

    return memo[x] = max(house[x] + rob(x+2), rob(x+1));
}

int main() {
    memset(memo, -1, sizeof(memo));
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> house[i];
    cout << rob(0) << endl;

    return 0;
}

/*
5
2 7 9 3 1

4
1 2 3 1
*/