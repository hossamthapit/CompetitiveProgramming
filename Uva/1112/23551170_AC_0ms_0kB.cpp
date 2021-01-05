#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx4[] = { 0, 0, 1, -1};
int dy4[] = { 1, -1, 0, 0};
int dx8[] = { -1,-1, 0, 1, 1, 1, 0, -1 };
int dy8[] = { 0 , 1, 1, 1, 0,-1,-1, -1 };
typedef long long ll;
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
vector < bool > vis;
int n , en , depth , m ;
vector < vector < pair < int , int > > > adj;

int bfs(int u){
    queue < pair < int , int > > q ;
    q.push({u,0});
    vis[u]=1;

    while(szz(q)){
        int v = q.front().first ;
        int dist = q.front().second;
        q.pop();
        for(auto e : adj[v])
        if(!vis[e.first]&&e.second+dist<=depth){
            vis[e.first]=1;
            q.push({e.first,e.second+dist});
        }
    }
    int c = 0 ;
    for(int i = 1 ; i<= n ;i++)
        c+= vis[i];
    return c;
}

bool dijkstra(int s  , int reach){
    int OO = INT_MAX;
    vector < ll > dist(n+1,OO);
    dist[s] = 0;
    priority_queue < pair < ll , ll > > pq;
    pq.push({0, s});
    while (!pq.empty()){
        pair < ll , ll >  f = pq.top(); pq.pop();
        int distance = -f.first, u = f.second;
        if (distance > dist[u])continue;
        for(auto node : adj[u])
            if (dist[u] + node.first < dist[node.second])
                pq.push({-(dist[node.second]=dist[u] + node.first), node.second});
    }
    //cout << s << " " << reach << " " << dist[reach] << endl;
    return (dist[reach]<=depth&&dist[reach]!=OO);
}


int main(){file();

    int t ;
    cin >> t ;
    while(t--){
        cin >> n >> en >> depth >> m ;
        vis = vector < bool > (n+1,0);
        adj = vector < vector < pair < int , int > > >  (n+1);
        while(m--){
            int a , b , c ;
            cin >> a >> b >> c ;
            adj[a].push_back({c,b});
        }
        int c = 0 ;
        for(int i = 1 ; i<= n ;i++)
            c+=dijkstra(i,en);

       // cout << bfs(en) << endl;
        cout << c << endl;
        if(t)cout << endl;
    }
}
