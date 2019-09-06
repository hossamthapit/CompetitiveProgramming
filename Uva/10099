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

struct edge{
    int from , to ;
    ll w ;
    edge(int from , int to , double w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const{
        return w < e.w;
    }
};

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

vector < edge >  MST_kruskal(vector < edge > edgeList , int n){
    unionFind uf(n);
    vector < edge > edges ;
    ll mstCost = 0 ;
    priority_queue < edge > q ;
    for(auto p : edgeList)q.push(p);

    while(!q.empty()){
        edge p = q.top() ; q.pop();
        if(uf.unionSets(p.from,p.to)){
            mstCost+=p.w;
            edges.push_back(p);
        }
    }
    return edges;
}

vector < vector < pair < int , int > > > adj ;
bool vis[1002];

int bfs(int u , int target){
    queue < pair < int , int > > qu ;
    qu.push({u,1e9});

    while(szz(qu)){
        pair < int , int > p = qu.front();qu.pop();
        vis[p.first]=1;
        if(p.first==target)return p.second;
        for(auto e : adj[p.first]){
            if(!vis[e.first]){
                qu.push({e.first,min(e.second,p.second)});
            }
        }
    }
}

int main(){file();

    int k = 1 , cities , roads , passengers , startt , endd ;
    while(cin >> cities >> roads && cities && roads){
        vector < edge > vv;
        memset(vis,0,sizeof vis);
        adj = vector < vector < pair < int , int > > > (cities);

        for(int i = 0 ; i < roads ;i++){
            int a , b, c ;
            cin >> a >> b >> c ;
            a--;b--;
            edge ee(a,b,c);
            vv.push_back(ee);
        }
        cin >> startt >> endd >> passengers ;
        startt--;endd--;

        vector < edge > p = MST_kruskal(vv,cities);

        //for(auto e : p)cout << e.from << " " << e.to << " " << e.w << endl;cout << endl;

        for(auto e : p){
            adj[e.from].push_back({e.to,e.w});
            adj[e.to].push_back({e.from,e.w});
        }

        int mnCapacity = bfs(startt,endd) ;

        int l = 1 , r = passengers , mid , ans;

        while(l<=r){
            mid = (l+r)/2;

            if(mid+passengers<=mid*mnCapacity){
                ans = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }

        cout << "Scenario #" << k++ <<endl;
        cout <<  "Minimum Number of Trips = "  << ans << endl << endl;
    }
}
