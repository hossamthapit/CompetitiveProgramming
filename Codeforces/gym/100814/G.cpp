#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx4[] = { 0, 0, 1, -1};
int dy4[] = { 1, -1, 0, 0};
int dx8[] = { -1,-1, 0, 1, 1, 1, 0, -1 };
int dy8[] = { 0 , 1, 1, 1, 0,-1,-1, -1 };
typedef long long ll;
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
ll n, length , m  , oo = 1e18;
vector < vector < pair < int , pair < int , int > > > > adj;

bool dijkstra(int mid){
    vector < ll > dist(n+1,oo);
    dist[1] = 0;
    priority_queue < pair < ll , pair < int , int > > > pq;
    pq.push({0, {1,0}});
    while (!pq.empty()){
        pair < ll , pair < int , int > >  f = pq.top(); pq.pop();
        ll distance = -f.first, u = f.second.first;
        if (distance > dist[u])continue;
        for(auto node : adj[u])
            if(node.second.second>mid)continue;
            else if(dist[u] + node.first>=length)continue;
            else if (dist[u] + node.first < dist[node.second.first])
                pq.push({-(dist[node.second.first]=dist[u] + node.first),{node.second.first,node.second.second}});
    }
    return dist[n]!=oo;
}

int main(){file();

    int t ;
    cin >> t ;
    while(t--){
        cin >> n >> m >> length;
        adj = vector < vector < pair < int , pair < int , int > > > >  (n+1);

        set < int > st ;
        vector < int > values ;

        while(m--){
            ll a , b , c , w ;
            cin >> a >> b >> c >> w ;
            adj[a].push_back({c,{b,w}});
            adj[b].push_back({c,{a,w}});
            st.insert(w);
        }

        for(auto e : st)values.push_back(e);
        ll l = 0 , r = szz(values)-1 , mid , ans = -1 ;

        while(l<=r){
            mid = (l+r)/2;
            if(dijkstra(values[mid])){
                ans = values[mid] ;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout << ans << endl;
    }
}
