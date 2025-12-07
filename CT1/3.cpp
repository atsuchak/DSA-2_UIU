#include <bits/stdc++.h>
using namespace std;

int cnt_major(vector<int> a, int st, int fn, int cnt) {
    if(st >= fn) return cnt++;

    int mid = st+fn / 2;
    
    bool chk = 1;
    for(int i = 0; i < mid-1; i++)
        if(abs(a[i]-a[i+1]) != 0) chk = 0;
    if(chk) return a[st];
    
    for(int i = mid; i < fn-1; i++)
        if(abs(a[i]-a[i+1]) != 0) chk = 0;
    if(chk) return a[mid]; 
}

bool tmp(vector<int> a, int st, int fn, int x) {
    if(a[st] == a[fn]) return 1;

    int mid = st+fn / 2;
    
    int lftSide = tmp(a, st, mid, x);
    int rghtSide = tmp(a, mid+1, fn, x);

    if(a[lftSide] == x && a[rghtSide] == x) return 1;
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i =0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            if(a[i] < a[j]) swap(a[i], a[j]);

    int mx = *max_element(a.begin(), a.end());

    mx++;
    vector<int> str(mx, 0);
    for(int i = 0; i < n; i++) str[a[i]]++;
    
    int x = 0;
    int mxStr = *max_element(str.begin(), str.end());
    for(int i = 0; i < str.size(); i++) 
        if(mxStr == str[i]) x = i;

    cout << x << endl;

    if(tmp(a, 0, n, x)) cout << x << endl;
    else cout << "HEllo" << endl;
    
    return 0;
}