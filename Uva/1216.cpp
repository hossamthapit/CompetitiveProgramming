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
    int from , to , w ;
    edge(int from , int to , int w):from(from),to(to),w(w){}
    bool operator < (const edge& e)const{
        return w > e.w;
    }
};

int  MST_kruskal(vector < edge > edgeList , int n , int transmitter){
    unionFind uf(n);
    vector < edge > edges ;
    int mx = 0;
    if(uf.forests<=transmitter)return 0 ;

    priority_queue < edge > q ;
    for(auto p : edgeList)q.push(p);

    while(!q.empty()){
        edge p = q.top() ; q.pop();

        if(uf.unionSets(p.from,p.to)){
            if(uf.forests+1<=transmitter)break;
            mx = max(mx,p.w);
            edges.push_back(p);
        }
    }
    return mx;
}

int dist(int x , int y , int x1 , int y1){
    return ceil(sqrt((x-x1+0LL)*(x-x1)+(y-y1)*(y-y1+0LL)));
}

int main(){file();

    int t , tansmitter ;
    cin >> t ;
    while(t--){
        cin >> tansmitter ;
        int a , b , c = 0;
        vector < pair < int , int > > locations;
        while(cin >> a && a!=-1 && cin >> b){
            locations.push_back({a,b});
            c++;
        }
        vector < edge > edges;

        for(int i = 0 ; i < szz(locations);i++){
            for(int k = i+1 ; k < szz(locations);k++){
                edge ee(i,k,dist(locations[i].first,locations[i].second,locations[k].first,locations[k].second));
                edges.push_back(ee);
            }
        }
        cout << MST_kruskal(edges,c,tansmitter) << endl;
    }
}
