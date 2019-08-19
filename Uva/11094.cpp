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

char grid[40][40];
bool vis[40][40];
int c = 0 , valid1 = 1 , xx , yy;

bool valid(int x , int y , int n , int m){
    return (x>=0&&y>=0&&x<n&&y<m);
}

void GridFill(int x , int y , int n , int m){

    if(!valid(x,y,n,m)||grid[x][y]!=grid[xx][yy]||vis[x][y])return;
    vis[x][y]=1;
    c++;
    if(x==xx&&y==yy)valid1 = 0 ;
    for(int i = 0 ; i < 4 ;i++)
        if(y+dy[i]>=m)GridFill(x+dx[i],0,n,m);
        else if(y+dy[i]<0)GridFill(x+dx[i],m-1,n,m);
        else GridFill(x+dx[i],y+dy[i],n,m);
}

int main()
{

    file();
    int n , m ;
    while(cin >> n >> m ){
        memset(vis,0,sizeof vis);
        int mx = 0 ;
        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < m ;k++)
                cin >> grid[i][k];
        cin >> xx >> yy ;

        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < m ;k++){
                GridFill(i,k,n,m);
                if(valid1)
                    mx = max(mx,c);
                c=0;
                valid1=1;
            }
        cout << mx << endl;
    }
}
