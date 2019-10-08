#include<bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif
#define stop(x) {cout<<x<<endl;exit(0);}
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define TRACE3(x,y,z) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << endl;
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

vector < vector < pair < ll , ll > > > adj;
vector < ll > dist;
ll OO = INT_MAX;

void dijkstra(int s){
    dist[s] = 0;
    priority_queue< pair < ll , ll > , vector<pair < ll , ll > >, greater<pair < ll , ll > > > pq;
    pq.push({0, s});
    while (!pq.empty()){
        pair < ll , ll >  f = pq.top();
        pq.pop();
        int d = f.first, u = f.second;
        if (d > dist[u])
            continue;
        for (int j = 0; j < szz(adj[u]); j++)
        {
            pair < ll , ll > v = adj[u][j];
            if (dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main(){file();

    int t , n , m , u , cost , q , s , d , v;
    cin >> t ;
    for(int e = 1 ; e <= t ;e++){

        cin >> n >> m >> s >> d ;
        adj = vector < vector < pair < ll , ll > > > (n);
        dist = vector < ll > (n,OO);

        for(int i = 0 ; i < m ;i++){
            cin >> u >> v >> cost ;
            adj[u].push_back({v,cost});
            adj[v].push_back({u,cost});
        }
        dijkstra(s);
        if(dist[d]!=OO)cout << "Case #" << e << ": " << dist[d] << endl;
        else cout << "Case #" << e << ": " <<"unreachable" << endl;
    }
}
