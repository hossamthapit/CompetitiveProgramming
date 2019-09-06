#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
using namespace std;
#define endl '\n'
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("out.txt", "w", stdout);
    #endif
}

/// MST_Kruskal

double dist(double x , double y , double x1 , double y1){
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}

struct unionFind{
    vector < int > rankk , parent ;
    int forests ;
    unionFind(int n){
        rankk = vector < int > (n) , parent = vector < int > (n);
        forests = n ;
        for(int i = 0 ; i < n ;i++){
            parent[i]=i;
            rankk[i]=1;
        }
    }
    int findSet(int x){
        if(x==parent[x])return x ;
        return parent[x] = findSet(parent[x]);
    }
    void link(int x , int y){
        if(rankk[x]>rankk[y])swap(x,y);
        parent[x]=y;
        if(rankk[x]==rankk[y])rankk[y]++;
    }
    bool unionSets(int x , int y){
        x = findSet(x) , y = findSet(y);
        if(x!=y){
            link(x,y);
            forests--;
        }
        return x!=y;
    }
    bool sameSet(int x , int y){
        return findSet(x)==findSet(y);
    }
    vector < vector < int > > connectedComponent(){
        vector < vector < int > > comps(szz(parent));
        for(int i = 0 ; i < szz(parent);i++){
            comps[findSet(i)].push_back(i);
        }
    }
};

struct edge{
    int from , to ;
    double w ;
    edge(int from , int to , double w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const{
        return w > e.w;
    }
};

pair < double , vector < edge > >  MST_kruskal(vector < edge > edgeList , int n){
    unionFind uf(n);
    vector < edge > edges ;
    double mstCost = 0 ;
    priority_queue < edge > q ;
    for(auto p : edgeList)q.push(p);

    while(!q.empty()){
        edge p = q.top() ; q.pop();
        if(uf.unionSets(p.from,p.to)){
            mstCost+=p.w;
            edges.push_back(p);
        }
    }
  ///  if(szz(edges)!=n-1)return -1;

    return {mstCost,edges};

}

vector < vector < pair < int , double > > > adj;
bool vis[100004];

double bfs(int u){
    queue < pair < int , double > > qu ;
    qu.push({u,-1});

    while(szz(qu)){
        pair < int , double > p = qu.front() ; qu.pop();
        vis[p.first]=1;
        if(p.first==1)return p.second;

        for(auto e : adj[p.first]){
            if(!vis[e.first]){
                qu.push({e.first,max(p.second,e.second)});
            }
        }
    }
}


int main(){file();

    int n , t = 1 ;
    cout << fixed << setprecision(3) ;
    while(cin >> n&&n){
        memset(vis,0,sizeof vis);
        vector < edge > vv;
        vector < pair < int , int > > v(n) ;
        adj = vector < vector < pair < int , double > > > (n);
        for(int i = 0 ; i < n ;i++)
            cin >> v[i].first >> v[i].second;

        for(int k = 0 ; k < n ; k++){
            for(int i = k+1 ; i < n ;i++){
                edge e(i,k,dist(v[i].first,v[i].second,v[k].first,v[k].second));
                vv.push_back(e);
            }
        }

        for(auto p : MST_kruskal(vv,n).second){
            adj[p.from].push_back({p.to,p.w});
            adj[p.to].push_back({p.from,p.w});
        }
        cout << "Scenario #" << t++ << endl;
        cout << "Frog Distance = " << bfs(0) << endl << endl;
    }
}
