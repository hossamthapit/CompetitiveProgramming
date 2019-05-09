#include<bits/stdc++.h>
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
#define all(x) x.begin(),x.end()
#define szz(s) int(s.size())
typedef long long ll;
#define endl '\n'
using namespace std;
void file(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}
int vis[55][55] , n , m ;
char ar[55][55];

bool valid(int x , int y ){
    return(x>=0&&y>=0&&x<n&&y<m);
}

void connect(int x , int y){
    if(!valid(x,y)||vis[x][y]||ar[x][y]!='#')return;
    vis[x][y]=1;
    for(int i = 0 ; i < 4; i++)
       connect(x+dx[i],y+dy[i]);
}


int main(){
    file();

    char ch  ;
    int c = 0;
    cin >> n >> m ;
    for(int i  = 0 ; i < n ;i++){
        for(int k = 0 ; k < m ;k++){
            cin >> ar[i][k];
            if(ar[i][k]=='#')c++;
        }
    }
    if(c<3)return cout << -1 , 0 ;

    for(int e1 = 0 ; e1 < n ; e1++){
        for(int e2 = 0 ; e2 < m ; e2++){
            if(ar[e1][e2]=='#'){
                ar[e1][e2]='.';
                int cnt = 0 ;
                memset(vis,0,sizeof vis);
                for(int i  = 0 ; i < n;i++){
                    for(int k = 0 ; k < m ;k++){
                        if(ar[i][k]=='#'&&!vis[i][k]){connect(i,k);cnt++;}
                    }
                }
                if(cnt>1)return cout << 1 , 0 ;
                ar[e1][e2]='#';
            }
        }
    }
    cout << 2 << endl;
}

