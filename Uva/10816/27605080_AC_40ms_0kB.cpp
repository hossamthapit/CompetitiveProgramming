#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
int dx[] = { 0,0,-1,1,1,-1,-1,1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
#define all(x) x.begin(),x.end()
#define szz(x) int(x.size())
typedef long long ll;
using namespace std;
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl;

void file() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    if (freopen("input.txt", "r", stdin));
    if (freopen("output.txt", "w", stdout));
#endif
}


struct edge {
    int to;
    double w , d;
    edge(int to, double w , double d) :to(to), w(w) , d(d) {}
    bool operator < (const edge& e)const {
        return d > e.d;
    }
};


int nn;
double MAXX = 0x3f3f3f;
vector < int > parent;
vector < vector < edge > > adj;

double dijkstra(int s, int reach , double mx) {
    vector < double > dist(nn, MAXX);
    dist[s] = 0;
    priority_queue < edge > pq;
    pq.push(edge(s,0,0));

    while (!pq.empty()) {
        edge f = pq.top(); pq.pop();
        double distance = f.d, u = f.to;
        if (u == reach)break;
        if (distance > dist[u])continue;
        for (auto node : adj[u])
            if (node.w > mx)continue;
            else if (dist[u] + node.d < dist[node.to]) {
                pq.push({node.to , node.w , (dist[node.to] = dist[u] + node.d) });
                parent[node.to] = u;
            }
    }
    return dist[reach];
}

int main() {

    file();

    int n , m ;
    while (cin >> n >> m) {

        cout << fixed << setprecision(1);
        nn = n;
        
        int from, to;
        adj = vector < vector < edge > >(n);
        cin >> from >> to; from--; to--;

        vector < double > weatherDeg;
        for (int i = 0; i < m; i++) {
            int a, b; double c, d;
            cin >> a >> b >> c >> d;

            weatherDeg.push_back(c);
            a--; b--;
            adj[a].push_back(edge(b, c, d));
            adj[b].push_back(edge(a, c, d));
        }
        

        sort(all(weatherDeg));
        int l = 0, r = szz(weatherDeg) - 1, mid;
        double mnWeth = 0;
        double ans = 0;


        vector < int > parentSave;

        while (l <= r) {
            mid = (l + r) / 2;

            parent = vector < int >(n, -1);
            
            double sol = dijkstra(from, to, weatherDeg[mid]);
            if (sol != MAXX) {
                mnWeth = weatherDeg[mid];
                ans = sol;
                parentSave = parent;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        vector < int > path;
        while (to != -1) {
            path.push_back(to);
            to = parentSave[to];
        }
        reverse(all(path));
        
        for (int i = 0; i < szz(path); i++)
            if (!i)cout << path[i]+1; 
            else cout << " " << path[i]+1;

        cout << endl;
        cout << ans << " " << mnWeth << endl;


    }


}