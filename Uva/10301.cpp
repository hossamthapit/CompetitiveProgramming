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

vector < vector < int > > adj ;
vector < bool > vis;

struct circle{
    double x , y , rad ;
};

bool intersect(circle c1 , circle c2){
    bool ok = ((c1.rad-c2.rad)*(c1.rad-c2.rad)<=(c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
    return ok & ((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y) <= (c1.rad+c2.rad)*(c1.rad+c2.rad));
}
int c = 0 ;
void dfs(int u){
    vis[u]=1;
    c++;
    for(auto p : adj[u])
        if(!vis[p])
            dfs(p);
}

int main(){file();

    int n ;
    while(cin >> n && n!=-1){
       vector < circle > v(n);
       vis = vector < bool > (n);
       adj = vector < vector < int > > (n);

        for(int i = 0 ; i < n ;i++)
            cin >> v[i].x >> v[i].y >> v[i].rad ;

        for(int i = 0 ; i < n ;i++){
            for(int k = i+1 ; k < n ;k++){
                if(i==k)continue;
                if(intersect(v[i],v[k])){
                    adj[i].push_back(k);
                    adj[k].push_back(i);
                }
            }
        }
        int mx = 0 ;
        for(int i = 0 ; i < n ;i++)
            if(!vis[i]){
                dfs(i);
                mx = max(mx,c);
                c=0;
            }
        if(mx==1)cout << "The largest component contains " << mx << " ring." << endl;
        else cout << "The largest component contains " << mx << " rings." << endl;
    }
}
