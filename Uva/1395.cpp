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

int MST_kruskal(vector < edge > edgeList , int n , int startt){
    unionFind uf(n);
    int c = 0 ;
    priority_queue < edge > q ;
    for(int i = startt ; i < szz(edgeList) ;i++)q.push(edgeList[i]);
    int mn = INT_MAX, mx = INT_MIN;

    while(!q.empty()){
        edge p = q.top() ; q.pop();
        if(uf.unionSets(p.from,p.to)){
            c++;
            mn = min(mn,p.w);
            mx = max(mx,p.w);
        }
    }
    if(c!=n-1)return 1e9;
    return mx-mn;
}

int main(){file();

    int n , m , a ;
    while(cin >> n >> m && n){
        vector < edge > vv;
        for(int i = 0 ; i < m ;i++){
            int a , b , c ;
            cin >> a >> b >> c ;
            edge ee(--a,--b,c);
            vv.push_back(ee);
        }
        sort(all(vv));
        reverse(all(vv));
        int ans = 1e9;

        for(int i = 0 ; i < m ;i++)
            ans = min(ans,MST_kruskal(vv,n,i));
        if(ans==1e9)ans=-1;
        cout << ans << endl;

    }
}
