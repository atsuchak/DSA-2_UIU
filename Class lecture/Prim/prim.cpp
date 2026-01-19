#include <bits/stdc++.h>
#define pii pair<int, int>
#define inf INT_MAX

using namespace std;

int v, e;
vector<pii> adj[100];
int key[100], parent[100];
bool tree[100];

int prim() {
    for (int i = 1; i <= v; i++) {
        tree[i] = false;
        key[i] = inf;
    }
    int root = 1;
    parent[root] = -1;
    key[root] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(make_pair(key[root], root));
    while (not pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        tree[u] = true;
        for (pii p: adj[u]) {
            int v = p.first, w = p.second;
            if (not tree[v] and w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push(make_pair(key[v], v));
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= v; i++)
        sum += key[i];
    return sum;
}

int main() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    cout << prim() << endl;
    cout << "Parent array" << endl;
    for (int i = 1; i <= v; i++)
        cout << parent[i] << " ";
    cout << endl;
    cout << "Key array" << endl;
    for (int i = 1; i <= v; i++)
        cout << key[i] << " ";
    cout << endl;
}