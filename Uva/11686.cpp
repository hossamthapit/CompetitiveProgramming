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

vector < vector < int > > adj;
vector < int > vis;
vector < int > topSort;
bool valid = 1 ;

void dfs(int u , int n){
    vis[u]=1;
    for(auto p : adj[u]){

        if(!vis[p]){
            dfs(p,n);
        }
        else if(vis[p]==1){
            valid = 0 ;
        }
    }
    vis[u]=2;
    topSort.push_back(u);
}

int main()
{
    file();
    int n , m ;
    while(cin >> n >> m ){
        if(!n&&!m)break;
        adj = vector < vector < int > > (n+1);
        vis = vector < int > (n+1,0);
        valid = 1;
        vector < vector < int > > ans ;

        for(int i = 0 ; i < m ;i++){
            int a , b ;
            cin >> a >> b ;
            adj[b].push_back(a);
        }
            for(int i = 1 ; i <= n ;i++){
                if(!vis[i]){
                    dfs(i,n);
                    ans.push_back(topSort);
                    topSort.clear();
                }
            }
        if(valid)
            for(auto i : ans)
                for(auto p : i)
                    cout << p << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
}
