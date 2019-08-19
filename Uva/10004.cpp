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

bool IsBipartite(int u , int n){
    vector < int > col(n+1,-1);
    queue < int > qu ;
    qu.push(u);
    col[u]=1;

    while(!qu.empty()){
        int p = qu.front();
        qu.pop();
        for(auto e : adj[p])
            if(col[e]==-1){
                col[e]=1-col[p];
                qu.push(e);
            }
            else if(col[e]==col[p])
                return 0;
    }
    return 1;
}

int main()
{
    file();
    int n , m ;
    while(cin >> n){
        if(!n)break;
        cin >> m ;
        adj.clear();
        adj.resize(n+1);

        int a , b ;
        for(int i = 0 ; i < m ;i++){
            cin >> a >> b ;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(IsBipartite(a,n))cout << "BICOLORABLE." << endl;
        else cout << "NOT BICOLORABLE." << endl;
    }
}
