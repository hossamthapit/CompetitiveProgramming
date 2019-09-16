#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
using namespace std;
#define endl '\n'
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
vector < vector < int > > adj;
vector < int > dfsNum , dfsLow ;
vector < pair < int , int > > bridges;
map < pair < int , int > , bool > mpBridge;
int targanTimer;

void targan(int node, int parent){
    dfsNum[node] = dfsLow[node] = ++targanTimer;
    for (auto child : adj[node]){
        if (!dfsNum[child]){
            targan(child, node);
            dfsLow[node] = min(dfsLow[node], dfsLow[child]);
            if (dfsLow[child] > dfsNum[node]){
                mpBridge[{child,node}]=1;
                mpBridge[{node,child}]=1;
                bridges.push_back({ min(child,node),max(child,node) });
            }
        }
        else if (child != parent){
            dfsLow[node] = min(dfsLow[node], dfsNum[child]);
        }
    }
}
int main()
{
    file();

    int n ,m,ans=0;
    cin >> n >> m ;
    targanTimer = 1 ;
    adj = vector < vector < int > > (n);
    dfsNum = dfsLow = vector < int > (n);
    bridges = vector < pair < int , int > >() ;
    map < pair < int , int > , int > mp;
    vector < pair < int , int > > edges(m);

    for (int i = 0; i < m; i++)
    {
        int x , y ;
        cin >> x >> y ;
        x--;y--;
        mp[{x,y}]=1;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges[i] = {x,y};
    }
    for(int i=0; i<n; i++)
        if(!dfsNum[i])
            targan(i,-1);

    for(auto r : bridges)
        if(mp[{r.first,r.second}]+mp[{r.second,r.first}]==1)
            ans++;
    cout << ans << endl;
    for(int i = 0 ; i < m ;i++){
        int x = edges[i].first , y = edges[i].second;
        if(mpBridge[{x,y}]&&mp[{x,y}]+mp[{y,x}]==1)
            cout << i+1 << " ";
    }
}
