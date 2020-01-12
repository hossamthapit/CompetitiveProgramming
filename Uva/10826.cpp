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
int n, s , m  ,e;
vector < int > parent , lastparent ;
vector < vector < pair < double , pair < int , double > > > > adj;


double dijkstra(int s  , int reach , double mid){
    int OO = INT_MAX;
    parent = vector < int > (n+1);
    vector < double > dist(n+1,OO);
    dist[s] = 0;
    priority_queue < pair < double , pair < int , double > > > pq;
    pq.push({0, {s,0}});
    while (!pq.empty()){
        pair < double , pair < int , double> >  f = pq.top(); pq.pop();
        int u = f.second.first;
        if (-f.first > dist[u])continue;
        for(auto node : adj[u])
            if(node.second.second>mid)continue;
            else if (dist[u] + node.first < dist[node.second.first]){
                parent[node.second.first] = u;
                pq.push({-(dist[node.second.first]=dist[u] + node.first),{node.second.first,node.second.second}});
            }
    }
    return (dist[reach]!=OO ? dist[reach] : -1);
}

int main(){file();

    while(cin >> n){
        cin >> m >> s >> e ;
        adj = vector < vector < pair < double , pair < int , double > > > >  (n+1);
        set < double > st ;
        vector < double > values ;
        cout << fixed << setprecision(1) ;
        while(m--){
            int a , b ;
            double c , d ;
            cin >> a >> b >> c >> d ;
            adj[a].push_back({d,{b,c}});
            adj[b].push_back({d,{a,c}});
            st.insert(c);
        }
        for(auto e : st)values.push_back(e);

        int l = 0 , r = szz(values)-1  , mid ;
        double ans = -1 , len ;

        while(l<=r){
            mid = (l+r)/2;
            double sol = dijkstra(s,e,values[mid]);
            if(sol!=-1){
                ans = values[mid] ;
                len = sol;
                r = mid-1;
                lastparent = parent;
            }
            else
                l = mid+1;
        }
        int w = lastparent[e];
        vector < int > path;

        path.push_back(e);
        while(w!=s && szz(path)<100){
            path.push_back(w);
            w = lastparent[w];
        }
        path.push_back(s);
        reverse(all(path));
        cout << path[0];
        for(int i = 1 ; i < szz(path);i++)
            cout << " " << path[i] ;cout << endl;
        cout << len << " " << ans << endl;
    }
}
