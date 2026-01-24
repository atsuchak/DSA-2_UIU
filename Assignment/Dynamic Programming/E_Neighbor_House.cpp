// --------------------------------------------------------------- //
// --------------------------------------------------------------- //
// -- If it works, don't touch it                              --- //
// -- Dedicated to the test case I forgot to consider          --- //
// -- Logic is a systematic way of going wrong with confidence --- //
// --------------------------------------------------------------- //
// --------------------------------------------------------------- //

//Problem link: https://vjudge.net/contest/772656#problem/E

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


int cost[25][3];
int memo[25][3];
int n;

int res(int i, int clr) {
    if(i == n) return 0;
    if(memo[i][clr] != -1) return memo[i][clr];

    int mx = INT_MAX;
    for(int c = 0; c < 3; c++) 
        if(c != clr) mx = min(mx, cost[i][c] + res(i+1, c));

    return memo[i][clr] = mx;
}

void solve(int t_idx) {
    cin >> n;
    for(int i=0;i<n;i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    memset(memo, -1, sizeof(memo));
    
    int ans = min({res(0, 0), res(0, 1), res(0, 2)});
    cout << "Case " << t_idx << ": " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("D:/File/input.txt", "r", stdin);
        freopen("D:/File/output.txt", "w", stdout);
        freopen("D:/File/error.txt", "w", stderr);
    #endif

    int t_case = 1;
    cin >> t_case;

    int i = 1;
    while (i <= t_case) {
        solve(i);
        i++;
    }

    return 0;
} 