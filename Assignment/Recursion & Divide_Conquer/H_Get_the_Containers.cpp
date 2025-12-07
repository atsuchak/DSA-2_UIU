#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << " = "; _print(x); cerr << endl; 
#else 
    #define debug(x)
#endif

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void _print(int n) {cerr << n;}
void _print(ll n) {cerr << n;}
void _print(double n) {cerr << n;}
void _print(char n) {cerr << n;}
void _print(string n) {cerr << n;}
void _print(bool n) {cerr << n;}

template<class T, class V> void _print(pair<T, V> p) {
    cerr << "("; _print(p.ff); cerr << ", "; _print(p.ss); cerr << ")";}
template<class T> void _print(vector<T> v) {
    cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> s) {
    cerr << "[ "; for(T i : s) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(map<T, V> m) {
    cerr << "[ "; for(auto i : m) {_print(i); cerr << " ";} cerr << "]";}

bool canFill(vl& capacities, ll mxCap, int m) {
    int usedContain = 1;
    ll sum = 0;
    for (ll cap : capacities) {
        if (cap > mxCap) return 0;
        if (sum + cap > mxCap) {
            usedContain++;
            sum = cap;
            if (usedContain > m) return 0;
        } else sum += cap;
    }
    return 1;
}

void solve() {
    int n, m; cin >> n >> m;
    
    vl vessel(n);
    ll mxVessel = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> vessel[i];
        mxVessel = max(mxVessel, vessel[i]);
        sum += vessel[i];
    }

    if (m >= n) {
        cout << mxVessel << endl;
        return;
    }

    ll lo = mxVessel, hi = sum;
    ll ans = sum;

    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (canFill(vessel, mid, m)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        // freopen("D:/File/input.txt", "r", stdin);
        // freopen("D:/File/output.txt", "w", stdout);
        freopen("D:/File/error.txt", "w", stderr);
    #endif

    int t_case = 1;
    cin >> t_case;

    int n = 1;
    while (t_case--) {
        cout << "Case " << n << ": ";
        solve();
        n++;
    }

    return 0;
}