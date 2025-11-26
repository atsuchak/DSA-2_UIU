#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

bool chk(ll minDist, int c, vl a) {
    int cow = 1; 
    ll lst = a[0];

    for (int i = 1; i < sz(a); i++) {
        if (a[i] - lst >= minDist) {
            cow++;
            lst = a[i];
            
            if (cow == c) return 1;
        }
    }
    return 0;
}

ll res(ll lo, ll hi, int c, vl a) {
    if(lo >= hi) return lo - 1;

    ll mid = (lo + hi)/2;

    if (chk(mid, c, a)) return res(mid + 1, hi, c, a);
    return res(lo, mid, c, a);
}

void solve() {
    int n, c; cin >> n >> c;

    vl a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    ll hi = a[n-1] - a[0] + 1;

    cout << res(1, hi, c, a);
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

    while (t_case--) {
        solve();
    }

    return 0;
}