#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int ddy[] = { 1, -1, -1, 1};
int ddx[] = { 1, -1, 1, -1};
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) ll(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

/// MST_Kruskal

struct unionFind{
    vector < short > rankk , parent ;
    short forests ;
    unionFind(ll n){
        rankk = vector < short > (n) , parent = vector < short > (n);
        forests = n ;
        for(short i = 0 ; i < n ;i++){
            parent[i]=i;
            rankk[i]=1;
        }
    }
    short findSet(ll x){
        if(x==parent[x])return x ;
        return parent[x] = findSet(parent[x]);
    }
    void link(short x , short y){
        if(rankk[x]>rankk[y])swap(x,y);
        parent[x]=y;
        if(rankk[x]==rankk[y])rankk[y]++;
    }
    bool unionSets(short x , short y){
        x = findSet(x) , y = findSet(y);
        if(x!=y){
            link(x,y);
            forests--;
        }
        return x!=y;
    }
    bool sameSet(short x , short y){
        return findSet(x)==findSet(y);
    }
    vector < vector < short > > connectedComponent(){
        vector < vector < short > > comps(szz(parent));
        for(short i = 0 ; i < szz(parent);i++){
            comps[findSet(i)].push_back(i);
        }
    }
};

struct edge{
    short from , to ;
    ll w ;
    edge(short from , short to , ll w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const{
        return w > e.w;
    }
};

vector < edge >  MST_kruskal(vector < edge > edgeList , short n){
    unionFind uf(n);
    vector < edge > edges ;
    priority_queue < edge > q ;
    for(auto p : edgeList)q.push(p);

    while(!q.empty()){
        edge p = q.top() ; q.pop();
        if(uf.unionSets(p.from,p.to)){
            edges.push_back(p);
        }
    }
    return edges;
}

int matrix[2002][2002] , n;
vector < vector < pair < short , ll > > > adj;

bool checkTree(){
    for(short i = 0 ; i < n ;i++)
        for(short k = 0 ; k < n ;k++)
            if(i==k&&matrix[i][k])return false;
            else if(matrix[i][k]!=matrix[k][i])return false;
            else if(i!=k&&!matrix[i][k])return false;
    return 1;
}

bool bfs(short u , short n){
    vector < bool > vis(n);
    vector < ll > dist(n);
    queue < pair < short , ll > > qu ;
    qu.push({u,0});

    while(szz(qu)){
        pair < short , ll > p = qu.front() ; qu.pop();
        vis[p.first]=1;
        dist[p.first]=p.second;
        for(auto e : adj[p.first])
            if(!vis[e.first]){
                vis[e.first]=1;
                qu.push({e.first,p.second+e.second});
            }
    }
    for(short i = 0 ; i < n ;i++)
        if(matrix[u][i]!=dist[i])stop("NO");
}

int main()
{
    file();

    cin >> n  ;
    adj = vector < vector < pair < short , ll > > > (n);
    vector < edge > edges;

    for(short i = 0 ; i < n ;i++)
        for(short k = 0 ; k < n ; k++)
            cin >> matrix[i][k];
    if(!checkTree())return cout << "NO" << endl , 0 ;

    for(short i = 0 ; i < n ;i++)
    for(short k = i+1 ; k < n ;k++){
        edge ee(i,k,matrix[i][k]);
        edges.push_back(ee);
    }

    vector < edge > v = MST_kruskal(edges,n);

    for(auto p : v){
        adj[p.from].push_back({p.to,p.w});
        adj[p.to].push_back({p.from,p.w});
    }

    for(short i = 0 ; i < n;i++)
        bfs(i,n);

    cout << "YES" << endl;
}
