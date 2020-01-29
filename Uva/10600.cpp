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
};

struct edge{
    int from , to ;
    ll w ;
    edge(){}
    edge(int from , int to , ll w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const{
        return w > e.w;
    }
};

pair < vector < edge > , ll >  MST_kruskal(vector < edge > edgeList , int n , edge e){
    unionFind uf(n);
    vector < edge > edges ;
    ll mstCost = 0 ;
    priority_queue < edge > q ;
    for(auto p : edgeList)q.push(p);

    bool one = 1 ;
    while(!q.empty()){
        edge p = q.top() ; q.pop();
        if(one && p.from == e.from && p.to == e.to && p.w == e.w){one=0;continue;}
        if(uf.unionSets(p.from,p.to)){
            mstCost+=p.w;
            edges.push_back(p);
        }
    }
    if(szz(edges)!=n-1)mstCost = -1;
    return {edges,mstCost};

}

int main(){file();

    int t ;cin >> t ;
    while(t--){
        int n , m , mn = INT_MAX , mn2 = INT_MAX ;
        edge invalid(-1,-1,-1);
        cin >> n >> m ;
        vector < edge > v(m);

        for(int i = 0 ; i < m ;i++){
            cin >> v[i].from >> v[i].to >> v[i].w ;
            v[i].from--;
            v[i].to--;
        }
        pair < vector < edge > , ll > ret = MST_kruskal(v,n,invalid) , ret2 ;
        mn = ret.second;
        for(int i = 0 ; i < szz(ret.first);i++){
            ret2 = MST_kruskal(v,n,ret.first[i]);
            if(ret2.second!=-1){
                mn2 = min(ret2.second,mn2*1LL);
            }
        }
        cout << mn << " " << mn2 << endl;

    }
}
