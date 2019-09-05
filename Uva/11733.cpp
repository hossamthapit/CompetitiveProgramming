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
        return w > e.w;
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


pair < ll , int >  MST_kruskal(vector < edge > edgeList , int n){
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
  ///  if(szz(edges)!=n-1)return -1;
    return {mstCost,uf.forests};
}

int main(){file();

    int t , k = 1;
    cin >> t ;
    while(t--){
        int cities , roads  , airPortCount = 0 ;
        ll cost = 0;
        ll  airPortCost ;
        cin >> cities >> roads >> airPortCost ;
        vector < edge > vv;
        map < pair < int , int > , ll > mp;

        for(int i = 0 ; i < roads ;i++){
            int a , b ; ll c ;
            cin >> a >> b >> c ;
            a--;b--;
            if(c>=airPortCost)continue;
            if(mp[{a,b}])mp[{a,b}] = min(c,mp[{a,b}]);
            else mp[{a,b}]=c;
        }
        for(auto p : mp){
            edge ee(p.first.first,p.first.second,p.second);
            vv.push_back(ee);
        }

        pair < ll , int > p = MST_kruskal(vv,cities);
        cost = p.first + (p.second*airPortCost);
        airPortCount = p.second;
        cout << "Case #" << k++ << ": " <<  cost << " "  << airPortCount << endl;
    }
}
