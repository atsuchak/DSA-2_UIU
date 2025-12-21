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

ll grid[210][210];
ll memo[210][210];
int n;

ll maxPath(int r, int c) {
    int rows = 2 * n - 1;

    if (r == rows) return grid[r][c];
    if (memo[r][c] != -1) return memo[r][c];
    ll result = 0;
    if (r < n) result = grid[r][c] + max(maxPath(r + 1, c), maxPath(r + 1, c + 1));
    else {
        ll option1 = 0, option2 = 0;
        if (c <= rows - r) option1 = maxPath(r + 1, c);
        if (c - 1 >= 1) option2 = maxPath(r + 1, c - 1);
        
        result = grid[r][c] + max(option1, option2);
    }
    
    return memo[r][c] = result;
}

void solve() {
    int t; cin >> t;
    
    for(int i = 1; i <= t; i++) {
        cin >> n;
        int rows = 2 * n - 1;
        
        for(int i = 0; i <= rows + 5; i++) 
            for(int j = 0; j <= n + 5; j++) 
                memo[i][j] = -1, grid[i][j] = 0;
        
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= i; j++) 
                cin >> grid[i][j];
        
        for(int i = n + 1; i <= rows; i++) {
            int cols = rows - i + 1;
            for(int j = 1; j <= cols; j++) 
                cin >> grid[i][j];
        }
        
        cout << "Case " << i << ": " << maxPath(1, 1) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    int t_case = 1;

    while (t_case--) {
        solve();
    }

    return 0;
}