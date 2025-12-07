#include <bits/stdc++.h>
using namespace std;

int cnt_evn(vector<int> a, int n) {
    if(n == 1) return a[n-1]%2 == 0? 1 : 0;
    
    return cnt_evn(a, n-1) + (a[n-1]%2 == 0? 1 : 0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << cnt_evn(a, n) << endl;
    
    return 0;
}