#include <bits/stdc++.h>
using namespace std;


class Edge {

    public:
    int u, v, w;
};

int n, m;
Edge edgeList[100];

int kruskal() {
    for(int i = 0; i < n; i++) tree_ID[i] = i;

    sort(edgeList, edgeList + m, cmp);
    int total = 0;

    for(int i = 0; i < m; i++) {
        int u = edgeList[i].u;
        int v = edgeList[i].v;
        int w = edgeList[i].w;

        if(tree_ID[u] != tree_ID[v]) {
            total += w;
            for(int i = 0; i < n; i++)
                if(tree_ID[i] == tree_ID[u])
                    tree_ID[i] = tree_ID[v];
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("D:/File/input.txt", "r", stdin);
    freopen("D:/File/output.txt", "w", stdout);
#endif

    cin >> n >> m;
    for(int i = 0; i m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgeList[i] = Ege(u, v, w);
    }

    

    return 0;
}