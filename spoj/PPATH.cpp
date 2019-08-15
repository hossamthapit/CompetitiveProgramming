#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define stop(x) {cout<<x<<endl;exit(0);}
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;

void file()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector < int > primes;
vector < vector < int > > adj(10000);
bool vis[100002];

bool isPrime(int x){
    if(x%2==0)return 0 ;
    for(int i = 2 ; i*i<= x ;i++)
        if(x%i==0)return 0 ;
    return 1;
}

int Difference(int x , int y){
    int cnt = 0 ;

    while(x){
        cnt += ((x%10) != (y%10));
        x/=10;
        y/=10;
    }
    return cnt ;
}

void solve(){
    for(int i = 1000 ; i <10000 ; i++)
        if(isPrime(i))primes.push_back(i);

    for(int i = 0 ; i < szz(primes);i++){
        for(int k = i+1 ; k < szz(primes);k++){
            if(Difference(primes[i],primes[k])==1){
                adj[primes[i]].push_back(primes[k]);
                adj[primes[k]].push_back(primes[i]);
            }
        }
    }
}

int bfs(int u , int x){
    queue < pair < int , int > > qu ;
    qu.push({u,0});
    while(szz(qu)){
        pair < int , int > p = qu.front();
        vis[p.first]=1;
        qu.pop();
        for(auto e : adj[p.first]){
            if(e==x)return p.second+1;
            if(!vis[e]){
                qu.push({e,p.second+1});
            }
        }
    }
    return -1;
}

int main()
{
    file();
    solve();
    int t ;
    cin >> t ;
    while(t--){
        memset(vis,0,sizeof vis);
        int a , b ,ans ;
        cin >> a >> b ;
        ans = bfs(a,b);
        if(a==b)cout << 0 << endl;
        else if(ans==-1)cout << "Impossible" << endl;
        else cout << ans << endl;
    }
}
