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
vector < int > ans;
int vis[10005] ;
bool independant[10005] ;

void dfs(int u , vector < vector < int > >  adj){
    vis[u]=1;
    ans.push_back(u);
    for(auto p : adj[u])
        if(!vis[p])
            dfs(p,adj);
}

int main()
{
    file();

    int n , m ;
    while(cin >> n >> m){
        memset(vis,0,sizeof vis);
        memset(independant , 0 , sizeof independant);
        ans.clear();
        vector < vector < int > >  adj(n+1);

        for(int i = 0 ; i < m ;i++){
            int a , b ;
            cin >> a >> b ;
            adj[a].push_back(b);
            independant[b]=1;
        }
        for(int i = 1 ; i <= n ;i++){
            if(!independant[i]&&!vis[i]){
                dfs(i,adj);
            }
        }

        for(auto p : ans)
            cout << p << " ";
        cout << endl;
    }

}
