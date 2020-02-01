#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int n , m ;

struct edge {
    int to , color ;
    edge (int to , int color):to(to),color(color){}
};

vector < vector < edge > > adj;

int bfs(int start , int col , int to){
    deque < int > q ;
    q.push_back({start});
    vector < bool > vis(n,0);
    while(q.size()){
        int u = q.front();q.pop_front();
        if(vis[u])continue;
        vis[u]=1;
        if(u==to)return 1 ;
        for(edge e : adj[u]){
            if(e.color==col&&!vis[e.to]){
                q.push_back(e.to);
            }
        }
    }
    return 0 ;
}

int main(){file();

    cin >> n >> m ;
    set < int > colors;
    adj.resize(n);
    for(int i = 0 ; i < m ;i++){
        int a , b , c;
        cin >> a >> b >> c ;a--;b--;
        adj[a].push_back(edge(b,c));
        adj[b].push_back(edge(a,c));
        colors.insert(c);
    }

    int q ;
    cin >> q ;
    while(q--){
        int a , b ;
        cin >> a >> b ;a--;b--;
        int ans = 0 ;
        for(auto e : colors)
            ans += bfs(a,e,b);
        cout << ans << endl;
    }
}
