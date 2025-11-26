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

bool chk(ll mid, int n, int c, vl &a) {
    ll lst = a[0];
    int cnt = 1; 

    for (int i = 1; i < n; i++) {
        if (a[i] - lst >= mid) {
            cnt++;
            lst = a[i];
            if (cnt == c) return 1;
        }
    }
    return 0;
}

ll res(ll lft, ll rght, int n, int c, vl &a) {
    if (lft > rght) return rght; 

    ll mid = (lft + rght) / 2;

    if (chk(mid, n, c, a)) return res(mid + 1, rght, n, c, a);
    else return res(lft, mid - 1, n, c, a);
}

void solve() {
    int n, c; cin >> n >> c;

    vl a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));
    ll lo = 0;
    ll hi = a[n - 1] - a[0];

    cout << res(lo, hi, n, c, a) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("D:/File/input.txt", "r", stdin);
    freopen("D:/File/output.txt", "w", stdout);
#endif

    int t_case = 1;
    cin >> t_case;

    while (t_case--) {
        solve();
    }

    return 0;
}