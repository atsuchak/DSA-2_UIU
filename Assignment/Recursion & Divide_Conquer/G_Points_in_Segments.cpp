#include <bits/stdc++.h>
using namespace std;

int found(vector<int> &arr, int st, int fn, int a, int b) {
    if(st > fn) return 0;

    int mid = (st+fn) / 2;
    int midVal = arr[mid];

    if(midVal >= a && midVal <= b) return 1 + found(arr, st, mid-1, a, b) + found(arr, mid+1, fn, a, b);
    else if(midVal < a) return found(arr, mid+1, fn, a, b);
    else return found(arr, st, mid-1, a, b);
}

void solve() {
    int n, x; cin >> n >> x;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    while(x--) {
        int a, b; cin >> a >> b;
        cout << found(arr, 0, n-1, a, b) << endl;    
    }
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

    int n = 1;
    while (t_case--) {
        cout << "Case " << n << ": " << endl;
        solve();
        n++;
    }

    return 0;
}