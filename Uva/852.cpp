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
int hitO = 0 , hitX = 0 , cnt = 0;

bool isValid(int x , int y){
    return (x>=0&&y>=0&&x<9&&y<9);
}

void dfs(int x , int y , char a){

    if(!isValid(x,y))return ;
    if(a=='.'){
        if(grid[x][y]=='X')hitX = 1 ;
        else if(grid[x][y]=='O')hitO = 1 ;
    }
    if(vis[x][y]||grid[x][y]!=a)return ;
    cnt++;
    vis[x][y]=1;

    for(int i = 0 ; i < 4 ;i++)
        dfs(x+dx[i],y+dy[i],a);
}

int main()
{
    file();
    int t ;
    cin >> t ;
    while(t--){
        int X = 0 , O = 0;
        memset(vis,0,sizeof vis);

        for(int i = 0 ; i < 9 ;i++)
            for(int k = 0 ; k < 9 ;k++)
                cin >> grid[i][k];

        for(int i = 0 ; i < 9 ;i++)
            for(int k = 0 ; k < 9 ;k++){
                if(!vis[i][k])
                    if(grid[i][k]=='O'){
                        dfs(i,k,'O');
                        O+=cnt;
                    }
                    else if(grid[i][k]=='X'){
                        dfs(i,k,'X');
                        X+=cnt;
                    }
                    else {
                        dfs(i,k,'.');
                        if(!hitO&&hitX)X+=cnt;
                        else if(hitO&&!hitX)O+=cnt;
                    }
                cnt=0;
                hitO = 0 ;
                hitX = 0;
            }
        cout << "Black " << X << " White " << O << endl;
    }
}
