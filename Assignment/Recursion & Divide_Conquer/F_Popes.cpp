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
    int y, p; cin >> y >> p;
    
    vector<int> year(p);
    for (int i = 0; i < p; i++) cin >> year[i];
    
    int mxPopes = 0, fstYr = 0, lstYr = 0;
    
    for (int i = 0; i < p; i++) {
        int cnt = 1; 
        
        for (int j = i + 1; j < p; j++) {
            if (year[j] <= year[i] + y - 1) cnt++;
            else break;
        }
        
        if (cnt > mxPopes) {
            mxPopes = cnt; 
            fstYr = year[i]; 
            lstYr = year[i + cnt - 1];
        }
    }
    
    cout << mxPopes << " " << fstYr << " " << lstYr << endl;
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