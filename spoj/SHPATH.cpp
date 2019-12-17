#include<bits/stdc++.h>
#define DEBUG true
#ifdef ONLINE_JUDGE
#undef DEBUG
#define DEBUG false
#endif
#define stop(x) {cout<<x<<endl;exit(0);}
#define TRACE(x) if(DEBUG) cerr << #x << " = " << x << endl;
#define TRACE2(x,y) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << endl;
#define TRACE3(x,y,z) if(DEBUG) cerr << #x << " = " << x << " | " << #y << " = " << y << " | " << #z << " = " << z << endl;
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;
void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int n ;
int OO = INT_MAX;
vector < vector < pair < ll , ll > > > adj ;
int dijkstra(int s  , int reach){
    vector < ll > dist(n,OO);
    dist[s] = 0;
    priority_queue < pair < ll , ll > > pq;
    pq.push({0, s});
    while (!pq.empty()){
        pair < ll , ll >  f = pq.top(); pq.pop();
        int distance = -f.first, u = f.second;
        if (distance > dist[u])continue;
        for(auto node : adj[u])
            if (dist[u] + node.first < dist[node.second])
                pq.push({-(dist[node.second]=dist[u] + node.first), node.second});
    }
    return dist[reach];
}


int main(){file();

    ll a , b , t , m , c = 1;
    map < string , int > mp ;
    cin >> t ;
    while(t--){
        cin >> n ;
        adj = vector < vector < pair < ll , ll > > > (n);
        for(int k = 1 ; k<= n ;k++){
            string s;
            cin >> s ;
            mp[s]=k-1;
            cin >> m ;
            while(m--){
                cin >> a >> b ;
                adj[k-1].push_back({b,a-1});
                adj[a-1].push_back({b,k-1});
            }
        }
        int q ;
        cin >> q ;
        string s2 , s3 ;
        while(q--){
            cin >> s2 >> s3;
            cout << dijkstra(mp[s2],mp[s3]) << endl;
        }
    }
}
