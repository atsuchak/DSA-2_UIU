#include <bits/stdc++.h>
using namespace std;

int triFound(vector<int> a, int st, int end) {
    if(end == -1) return 0;

    return a[end] + triFound(a, st, end-1);
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << triFound(a, 0, n-1) << endl;
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
        cout << "Case " << n << ": ";
        solve();
    }

    return 0;
}