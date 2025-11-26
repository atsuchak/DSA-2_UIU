#include <bits/stdc++.h>
using namespace std;

int found(vector<int> a, int st, int end, int sg1, int sg2, int cnt) {
    if(st >= end) return cnt;

    if(a[end] >= sg1 && a[end] <= sg2) return cnt + found(a, st, end-1, sg1, sg2, cnt);
    if(a[st] >= sg1 && a[st] <= sg2) return cnt + found(a, st+1, end, sg1, sg2, cnt);
    found(a, st+1, end-1, sg1, sg2, cnt);
    
}

void solve() {
    int n, x; cin >> n >> x;

    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin >> ar[i];

    while(x--) {
        int a, b; cin >> a >> b;
        cout << found(ar, 0, n-1, a, b, 0) << endl;    
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    // freopen("D:/File/input.txt", "r", stdin);
    // freopen("D:/File/output.txt", "w", stdout);
#endif

    int t_case = 1;
    cin >> t_case;

    int n = 1;
    while (t_case--) {
        cout << "Case " << n << ": " << endl;
        solve();
        n++;
    }

    return 0;
}