#include <bits/stdc++.h>
using namespace std;

int print_sum(int n) {
    if(n == 0) return 0;

    return n%10 + print_sum(n/10);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;

    cout << print_sum(n) << endl;

    return 0;
}