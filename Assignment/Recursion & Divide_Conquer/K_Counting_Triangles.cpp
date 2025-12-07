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

void solve() {
    int n; cin >> n;

    vl arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    sort(all(arr));
    
    ll ans = 0;
    for (int i = 0; i < n; i++) 
        for (int j = i + 1; j < n; j++) {
            ll sum = arr[i] + arr[j];
            
            int left = j + 1, right = n - 1;
            int idx = -1;
            
            while (left <= right) {
                int mid = (left + right) / 2;

                if (arr[mid] < sum) {
                    idx = mid;
                    left = mid + 1;
                } else right = mid - 1;
            }
            
            if (idx != -1) ans += idx - j;
        }
        
    cout << ans;
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

    for (int i = 1; i <= t_case; i++) {
        cout << "Case " << i << ": ";
        solve();
        if (i < t_case) cout << endl;
    }

    return 0;
}