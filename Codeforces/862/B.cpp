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

ll n , o = 0 , z = 0 ;
vector < vector < int > > adj;

void bfs(int u){
    queue < int > qu ;
    vector < int > col(n+1,-1);
    qu.push(u);
    col[u]=0;

    while(szz(qu)){
        int v = qu.front();
        qu.pop();
        for(auto p : adj[v]){
            if(col[p]==-1){
                col[p]=!col[v];
                qu.push(p);
            }
        }
    }
    for(auto p : col){
        if(p==1)o++;
        else if(p==0)z++;
    }
}

int main()
{
    file();
    cin >> n ;
    adj.resize(n+1);

    int a , b ;
    for(int i = 0 ; i < n-1 ;i++){
        cin >> a >> b ;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(a);
    cout <<  (o*z) - (n-1) << endl;
}
