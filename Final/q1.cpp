#include<bits/stdc++.h>
using namespace std;

vector<bool> blocked;

class Edge {
    public: 
    int v, wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void Dijkstra(int src, vector<vector<Edge>> g, int v, int end) {
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;

    if(blocked[src]) return;

    vector<int> parent(v, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push(make_pair(0, src));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for(Edge e : g[u]) {
            int v = pq.top().first;
            if(blocked[v]) continue;
            if(dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;

                parent[e.v] = u;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }

    vector<int> path;
    for(int i = end; i != src; i = parent[i]) 
        path.push_back(i);

    reverse(path.begin(), path.end());

    for(int i = 0; i < v; i++)
        blocked[i]? cout << i+1 << " " << "INF" << endl : cout << i+1 << " " << dist[i] << endl;
    cout << endl;

    cout << "Path: ";
    for(int i = 0; i < path.size(); i++) 
        cout << path[i] << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nodes, edges; cin >> nodes >> edges;
    nodes++;
    int strt, end; cin >> strt >> end;


    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        blocked[x] = 1;
    }

    vector<vector<Edge>> g(nodes);
    for(int i = 0; i < edges; i++) {
        int u, v, wt; cin >> u >> v >> wt;

        g[u].push_back(Edge(v, wt));
    }

    Dijkstra(strt, g, nodes, end);

    return 0;
}