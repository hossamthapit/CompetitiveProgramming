#include <bits/stdc++.h>
#define write ofstream file_out ; file_out.open("output.txt");
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read ifstream file_in ; file_in.open("input.txt");
typedef long long ll;typedef unsigned long long ull;
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
#define rep(i,s,n) for(int i=s;i<n;i++)
#define all(x) x.begin(),x.end()
#define szz(x) ll(x.size())
#define stop exit(0);
using namespace std;
#define endl '\n'
/**************/
ll sum = 0 ;
vector < vector < int > >  graph ;
vector < pair < int , int >  > v ;
bool mn[100001] ;
bool vis[100001];

void dfs(int u){

    vis[u]=1;

    for(auto w : graph[u])
        if(!vis[w]){
      //      cout << u << " " << w << endl;
            dfs(w);
        }
}

int main(){fast write read

    int n , m , a , b , c ;
    cin >> n >> m ;n++;
    graph.clear();
    graph.resize(n);
    v.resize(n);
    memset(vis,0,sizeof(vis));

    rep(i,1,n){
        cin >> v[i].first;
        v[i].second=i;
    }

    sort(all(v));

    for(int i = 0 ; i < m ;i++){
        cin >> a >> b;
     //   if(v[b]>=v[a])mn[b]=1;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    for(auto i : v){
        if(!i.second)continue;
        if(!vis[i.second]){
      //  cout << i.second << " ";
            sum+=i.first;
            dfs(i.second);
        }
    }
    cout << sum << endl;

}
