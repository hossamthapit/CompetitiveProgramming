#include<bits/stdc++.h>
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
#define endl '\n'
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
typedef long long ll;
using namespace std;

void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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
    ll w ;
    edge(int from , int to , ll w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const{
        return w > e.w;
    }
};

vector < edge > MST_kruskal(vector < edge > edgeList , int n , vector < pair < int , int > > avil){
    unionFind uf(n);
    vector < edge > edges ;
    priority_queue < edge > q ;

    for(int i = 0 ; i < szz(avil);i++)
        uf.unionSets(avil[i].first,avil[i].second);

    for(auto p : edgeList)q.push(p);

    while(!q.empty()){
        edge p = q.top() ; q.pop();
        if(uf.unionSets(p.from,p.to)){
            edges.push_back(p);
        }
    }
    return edges;
}

ll dist(pair < ll , ll > p , pair < ll , ll > p1){
    return (p.first-p1.first)*(p.first-p1.first)+(p.second-p1.second)*(p.second-p1.second);
}

int main(){file();

    int t ;
    cin >> t ;
    while(t--){
        int n ;cin >> n ;
        vector < pair < int , int > > loc(n);
        for(auto &e : loc)cin >> e.first >> e.second ;
        vector < edge > edges;
        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < n ;k++)
                if(i!=k)edges.push_back(edge(i,k,dist(loc[i],loc[k])));

        int m ;cin >> m ;
        vector < pair < int , int > > avil(m);
        for(auto &e : avil){cin >> e.first >> e.second ;e.first--;e.second--;}
        
        vector < edge > ret = MST_kruskal(edges,n,avil);
        for(auto e : ret)
            cout << e.from+1 << " " << e.to+1 << endl;
        if(!szz(ret))cout << "No new highways need" << endl;
        if(t)cout << endl;
    }
}
