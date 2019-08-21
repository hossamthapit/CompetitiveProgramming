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
vector < vector < pair < ll , ll > > > adj;
vector < bool > vis;
ll mx , edge ;

void BFS(ll u){
    queue < pair < ll , ll > > qu ;
    qu.push({u,0});

    while(szz(qu)){
        pair < ll , ll > p = qu.front();
        qu.pop();
        if(p.second>mx){
            mx = p.second;
            edge = p.first;
        }
        mx = max(mx,p.second);
        vis[p.first]=1;
        for(auto v : adj[p.first])
            if(!vis[v.first])
                qu.push({v.first,v.second+p.second});
    }
}
int main()
{
    file();
    ll t ;
    cin >> t;
    while(t--){
        ll n ;
        cin >> n ;
        adj = vector < vector < pair < ll , ll > > > (50002);
        vis = vector < bool > (50002);
        mx = -1;
        ll a , b , c ;
        for(ll i = 0 ; i < n-1 ;i++){
            cin >> a >> b >> c ;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        BFS(a);
        vis = vector < bool > (50002);
        BFS(p);
        cout << mx << endl;
    }
}
