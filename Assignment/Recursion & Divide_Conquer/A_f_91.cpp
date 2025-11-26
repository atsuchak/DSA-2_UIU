#include <bits/stdc++.h>
using namespace std;

int f81(int n) {
    if(n >= 101) return n-10;

    return f81(f81(n+11));
}

void solve() {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    // freopen("D:/File/input.txt", "r", stdin);
    // freopen("D:/File/output.txt", "w", stdout);
#endif

    int t_case = 1;
    // cin >> t_case;

    while (t_case) {
        solve();

        int n; cin >> n;

        if(n == 0) break;
        cout << "f91(" << n << ") = " << f81(n) << endl;
    }

    return 0;
}