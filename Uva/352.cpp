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

bool valid(int x , int y , int n){
    return(x>=0&&y>=0&&x<n&&y<n);
}

void dfs(int x, int y , int n){

    if(!valid(x,y,n)||grid[x][y]=='0'||vis[x][y])return ;
    vis[x][y]=1;
    for(int i = 0 ; i < 8 ;i++)
        dfs(x+dx[i],y+dy[i],n);
}


int main()
{
    file();

    int n , Case = 1;
    while(cin >> n ){
        int ans = 0 ;
        memset(vis,0,sizeof vis);
        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < n ;k++)
                cin >> grid[i][k];

        for(int i = 0 ; i < n ;i++)
            for(int k = 0 ; k < n ;k++)
                if(grid[i][k]=='1'&&!vis[i][k]){
                    dfs(i,k,n);
                    ans++;
                }
        cout << "Image number " << Case << " contains " << ans << " war eagles." << endl;
        Case++;
    }
}
