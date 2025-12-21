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
    cerr << "("; _print(p.ff); cerr << ", "; _print(p.ss); cerr << ")";};
template<class T> void _print(vector<T> v) {
    cerr << "[ "; for(T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T> void _print(set<T> s) {
    cerr << "[ "; for(T i : s) {_print(i); cerr << " ";} cerr << "]";}
template<class T, class V> void _print(map<T, V> m) {
    cerr << "[ "; for(auto i : m) {_print(i); cerr << " ";} cerr << "]";}

bool inSet[10];
ll memo[15][15]; 

int m, n;
vi digits;

ll countWays(int pos, int lstDgt) {
    if (pos == n) return 1;  
    if (memo[pos][lstDgt] != -1) return memo[pos][lstDgt];
    
    ll total = 0;
    for (int d : digits) 
        if (abs(d - lstDgt) <= 2) total += countWays(pos + 1, d);
    
    return memo[pos][lstDgt] = total;
}

void solve() {
        memset(memo, -1, sizeof(memo));

        cin >> m >> n;
        digits.resize(m);
        for (int j = 0; j < m; j++) cin >> digits[j];

        ll result = 0;
        for (int d : digits) result += countWays(1, d);
        
        cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    int t_case;
    cin >> t_case;
    
    for (int i = 1; i <= t_case; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}