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

ll res(ll a, ll b, ll mid) {
    if (mid == 0) return 0;

    ll cnt = 0, tmp = mid;
    while(tmp > 0) {
        tmp /= 10;
        cnt++;
    }

    return a * mid + b * cnt;
}

void solve() {
    ll a, b, x; cin >> a >> b >> x;

    ll lft = 0;
    ll rght = 1000000000;
    ll ans = 0; 

    while(lft <= rght){
        ll mid = (lft+rght) / 2;

        if(res(a, b, mid) <= x){   
            ans = mid;
            lft = mid + 1;
        } else rght = mid - 1;
    }

    cout << ans << endl;
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

    while (t_case--) {
        solve();
    }

    return 0;
}