#include <bits/stdc++.h>
using namespace std;

pair<int, int> findBook(vector<int> a, int st, int end, int x, pair<int, int> &store) {
    if(st >= end) return store;

    if(a[st] + a[end] > x) return findBook(a, st, end-1, x, store);
    else if(a[st] + a[end] < x) return findBook(a, st+1, end, x, store);
    else {
        if((store.first == -1 && store.second == -1) || (a[end] - a[st]) < (store.second - store.first))
            store = make_pair(a[st], a[end]);
        return findBook(a, st+1, end-1, x, store);
    }
}

void solve() {
    int n; 
    
    while(cin >> n) {
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int x; cin >> x;

        sort(a.begin(), a.end());

        pair<int, int> store(-1, -1);
        findBook(a, 0, n-1, x, store);

        cout << "Peter should buy books whose prices are " << store.first << " and " << store.second << "." << endl << endl;
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
    // cin >> t_case;

    while (t_case--) {
        solve();
    }

    return 0;
}