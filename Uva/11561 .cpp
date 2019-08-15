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
bool vis[104][104];
char grid[104][104];
int n , m , gold = 0 , xx , yy , lastGold = 0;

bool valid(int x, int y){
    return (x>=0&&y>=0&&x<n&&y<m);
}

void filll(int x , int y){
    if(!valid(x,y)||vis[x][y]||grid[x][y]=='T'||grid[x][y]=='#')return ;
    vis[x][y]=1;

    bool valid = 1 ;
    for(int i = 0 ; i < 4 ;i++)
        if(grid[x+dx[i]][y+dy[i]]=='T')valid = 0;

   // cout <<x << " " << y <<  " " << grid[x][y] << " " << valid << endl;
    if(!valid){
        if(grid[x][y]=='G')lastGold++;
        return ;
    }
    if(grid[x][y]=='G')gold++;

    for(int i = 0 ; i < 4 ;i++)
        filll(x+dx[i],y+dy[i]);

}

int main()
{
    file();
    while(cin >> m >> n){
        memset(vis,0,sizeof vis);
        gold = 0 ;
        lastGold = 0 ;

        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < m ;k++){
                cin >> grid[i][k];
                if(grid[i][k]=='P'){
                    xx = i ;
                    yy = k ;
                }
            }
        filll(xx,yy);
        cout << gold + lastGold << endl;
    }
}
