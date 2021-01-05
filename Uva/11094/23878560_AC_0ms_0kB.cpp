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

char ar[21][21];
bool vis[21][21];
int n , m , x , y , c = 0 , mx = 0 ;

ll fixMod(int x , int mod){
    return ((x+mod)%mod);
}

bool valid(int a , int b){
    return (a>=0&&b>=0&&a<n&&b<m);
}

void dfs(int i , int j){
    if(vis[i][j])return ;
    vis[i][j]=1;
    if(i==x&&y==j)c-=400;
    c++;
    for(int e = 0 ; e < 4 ;e++){
        int xx = i+dx[e] , yy = fixMod(j+dy[e],m);
        if(ar[xx][yy]==ar[x][y]&&valid(xx,yy))
            dfs(xx,yy);
    }
}

int main(){file();

    while(cin >> n >> m){
        memset(vis,0,sizeof vis);
        mx = 0 ;
        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < m ;k++){
                cin >> ar[i][k];
            }
        }
        cin >> x >> y ;
        for(int i = 0 ; i < n ;i++){
            for(int k = 0 ; k < m ;k++){
                if(ar[i][k]==ar[x][y]&&!vis[i][k]){
                    dfs(i,k);
                    mx = max(mx,c);
                    c=0;
                }
            }
        }
        cout << mx << endl;
    }

}

