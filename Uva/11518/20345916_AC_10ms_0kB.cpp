#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}

vector < vector < int > > adj  ;
bool vis[10004];
int c = 0 ;

void dfs(int x){

    if(vis[x])return ;
    vis[x]=1;
    c++;

    for(auto f : adj[x]){
        if(!vis[f])
            dfs(f);
    }
}

int main(){file();

    int t ;
    cin >> t ;
    while(t--){
        c = 0 ;
        adj.clear();
        memset(vis,0,sizeof vis);
        
        int n , m , l ;
        cin >> n >> m >> l ;

        adj.resize(n+5);

        for(int i = 0 ; i < m ;i++){
            int a , b ;
            cin >> a >> b ;
            adj[a].push_back(b);
        }


        for(int i = 0 ; i < l ;i++){
            int a ;
            cin >> a ;
            dfs(a);
        }
        cout << c << endl;
    }






}
