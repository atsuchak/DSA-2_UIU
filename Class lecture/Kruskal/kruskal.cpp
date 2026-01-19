#include <bits/stdc++.h>

using namespace std;

class Edge {
public:    
    int u, v, w;
    Edge () {}
    Edge (int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int n, m;
Edge edgelist[100];
int tree_ID[100];
vector<Edge> taken;

bool cmp(Edge e1, Edge e2) {
    return e1.w >= e2.w;
}

int kruskal() {
    for (int i = 0; i < n; i++)
        tree_ID[i] = i;
    sort(edgelist, edgelist+m, cmp);
    int total = 0;
    for (int i = 0; i < m; i++) {
        int u = edgelist[i].u;
        int v = edgelist[i].v;
        int w = edgelist[i].w;
        if (tree_ID[u] != tree_ID[v]) {
            total += w;
            taken.push_back(edgelist[i]);
            int temp = tree_ID[u];
            for (int i = 0; i < n; i++)
                if (tree_ID[i] == temp)
                    tree_ID[i] = tree_ID[v];
        }
    }
    return total;
}

int main () {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist[i] = Edge(u, v, w);
    }
    cout << kruskal() << endl;
}