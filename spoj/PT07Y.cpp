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
vector < vector < int > >  adj;
int vis[10005] , parent[10005] , valid = 1 , c = 0;

void dfs(int u){
    vis[u]=1;
    for(auto p : adj[u]){
        if(!vis[p]){
            vis[p]=1;
            parent[p]=u;
            dfs(p);
        }
        else if(vis[p]==1)
            if(p!=parent[u]){
                valid = 0 ;
                return;
            }
        else if(vis[p]==2){
            valid = 0 ;
            return;
        }
    }
    vis[u]=2;
}

int main()
{
    file();
    int n , m ;
    cin >> n >> m ;
    adj.resize(n+1);

    for(int i = 0 ; i < m ;i++){
        int a , b ;
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1 ; i <= n ;i++){
        if(!vis[i]){
            dfs(i);
            c++;
        }
    }
    if(c==1&&valid)cout << "YES" << endl;
    else cout << "NO" << endl;
}
