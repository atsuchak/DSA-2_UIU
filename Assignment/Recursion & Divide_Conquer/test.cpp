#include <bits/stdc++.h>
using namespace std;

// Check if we can place C cows with at least dist "mid"
bool canPlace(long long mid, vector<long long> &a, int N, int C) {
    long long last = a[0];
    int cnt = 1; // first cow placed

    for (int i = 1; i < N; i++) {
        if (a[i] - last >= mid) {
            cnt++;
            last = a[i];
            if (cnt == C) return true;
        }
    }
    return false;
}

// Recursive binary search
long long solveRec(long long l, long long r, vector<long long> &a, int N, int C) {
    if (l > r) return r;  // r is the last valid answer

    long long mid = (l + r) / 2;

    if (canPlace(mid, a, N, C))
        return solveRec(mid + 1, r, a, N, C);
    else
        return solveRec(l, mid - 1, a, N, C);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int N, C;
        cin >> N >> C;

        vector<long long> a;        // create vector
        a.reserve(N);               // optional (not required for beginners)

        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;
            a.push_back(x);         // store each number
        }

        sort(a.begin(), a.end());

        long long low = 0;
        long long high = a[N - 1] - a[0];

        cout << solveRec(low, high, a, N, C) << "\n";
    }
}
