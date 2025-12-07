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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    // freopen("D:/File/input.txt", "r", stdin);
    // freopen("D:/File/output.txt", "w", stdout);
#endif

    ll y;
    while (cin >> y) {
        int p; cin >> p;
        
        vl a(p);
        for (int i = 0; i < p; i++) cin >> a[i];

        int best = 0;
        ll fstYr= 0, lstYr = 0;
        
        int j = 0;
        for (int i = 0; i < p; i++) {
            while (j < p && a[j] <= a[i] + y - 1) j++;
            
            int count = j - i;
            
            if (count > best) {
                best = count;
                fstYr = a[i];
                lstYr = a[j - 1]; 
            }
        }

        cout << best << " " << fstYr << " " << lstYr << endl;
    }

    return 0;
}