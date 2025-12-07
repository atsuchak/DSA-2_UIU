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

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
        // freopen("D:/File/input.txt", "r", stdin);
        // freopen("D:/File/output.txt", "w", stdout);
        freopen("D:/File/error.txt", "w", stderr);
    #endif

    int x = 1;
    int n, q;
    
    while (cin >> n >> q) {
        if (n == 0 && q == 0) break;
        
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        sort(all(a));
        cout << "CASE# " << x << ":\n";
        
        for (int i = 0; i < q; i++) {
            int query;
            cin >> query;
            
            int lft = 0, rght = n - 1;
            int pos = -1;
            
            while (lft <= rght) {
                int mid = (lft + rght) / 2;
                if (a[mid] == query) {
                    pos = mid;
                    rght = mid - 1; 
                } else if (a[mid] < query) lft = mid + 1;
                else rght = mid - 1;
            }
            
            if (pos != -1) cout << query << " found at " << (pos + 1) << endl;
            else cout << query << " not found" << endl;
        }
        x++;
    }

    return 0;
}