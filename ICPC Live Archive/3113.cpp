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
    return {mstCost,edges};
  ///  if(szz(edges)!=n-1)return -1;

}

int main(){file();

    int m , q , n ;
    double cableLength ;

    while(cin>>cableLength){
        cin >> n ;m=n;
        int cnt = 1;
        map < string , int > mp ;

        while(n--){
            string s ;
            cin >> s ;
            if(!mp[s])mp[s]=cnt++;
        }
        cin >> q ;
        vector < edge > vv ;
        while(q--){
            string s , k ;
            double w ;
            cin >> s >> k >> w;
            edge e(mp[s]-1,mp[k]-1,w);
            vv.push_back({e});
        }

        double needs = MST_kruskal(vv,m).first ;

        if(needs<=cableLength)
            cout << "Need " << needs << " miles of cable" << endl;
        else
            cout << "Not enough cable" << endl;
    }
}
