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
vector < int > vis , topSort;
int n , m;

void dfs(int u){

    vis[u]=1;
    for(auto p : adj[u])
        if(!vis[p])
            dfs(p);
    topSort.push_back(u);
}



int main()
{
    file();
    cin >> n >> m ;
    adj.resize(n+1);
    vis.resize(n+1,0);
    vector < vector < int > > ans;

    for(int k = 1 ; k <= m;k++){
        int a , b ;
        cin >> a;
        for(int i = 0 ; i < a ;i++){
            cin >> b ;
            adj[b].push_back(k);
        }
    }

    for(int i = 1 ; i <= n ;i++){
        if(!vis[i]){
            dfs(i);
            ans.push_back(topSort);
            topSort.clear();
        }
    }
    vector < int > res(n+1);
    int c = -1;
    for(auto p : ans){
        for(auto pp : p){
            if(c==-1)res[pp]=0;
            else res[pp] = c;
            c=pp;
        }
    }

    for(int i = 1 ; i<= n ;i++)
        cout << res[i] << endl;
}
