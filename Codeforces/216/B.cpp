#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;

void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector < vector < int > > adj ;
vector < int > vis , par ;
int cnt = 0 , n , cyc = 0 ;

void dfs(int u){
    vis[u]=1;
    cnt++;
    for(auto p : adj[u])
        if(!vis[p]){
            par[p]=u;
            dfs(p);
        }
        else if(vis[p]==1&&p!=par[u]){
            cyc = 1;
        }
    vis[u]=2;
}
int main()
{
    file();
    ll n , m , ans = 0;
    cin >> n >> m ;
    adj.resize(n+1);
    par.resize(n+1);
    vis.resize(n+1,0);
    while(m--){
        int a , b ;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1 ; i <= n ;i++){
        if(!vis[i]){
            par[i]=-1;
            dfs(i);
            ans+=(cyc&&cnt&1);
            cyc=cnt=0;
        }
    }
    if((n-ans)&1)ans++;
    cout << ans << endl;
}
