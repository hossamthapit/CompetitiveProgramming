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

int beforeMe = 0 , afterMe = 0 ;
vector < int > _time;
vector < bool > vis;

void dfs(int u , vector < vector < int > > &adj){
    if(vis[u])return ;
    vis[u]=1;
    beforeMe+=_time[u];
    for(auto e : adj[u])
        if(!vis[e])
            dfs(e,adj);
}

int main(){file();

    int n , m , _case = 1 ;
    while(cin >> n >> m){
        if(!n&&!m)break;
        int sum = 0;
        _time = vector < int > (n);
        vector < vector < int > > adj(n) , adj2(n);

        for(auto &e : _time){
            cin >> e ;
            sum+=e;
        }

        while(m--){
            ll a , b ; cin >> a >> b ;
            a--;b--;
            adj[a].push_back(b);
            adj2[b].push_back(a);
        }
        int q ; cin >> q ;
        cout << "Case #" << _case << ":" << endl;
        _case++;
        while(q--){
            int a ; cin >> a ;a--;
            vis = vector < bool > (n,0);
            dfs(a,adj);
            vis[a]=0;
            dfs(a,adj2);
            cout << max((sum-(afterMe))-(beforeMe-_time[a]),0) << endl;
            beforeMe = afterMe = 0;
        }
        cout << endl;
    }
}
