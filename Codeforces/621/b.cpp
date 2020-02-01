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

int grid[1001][1001];

bool valid(int x , int y){
    return (x>0&&y>0&&x<=1000&&y<=1000);
}

int main(){file();

    ll n , ans = 0;
    cin >> n ;

    while(n--){
        int a , b ;cin >> a >> b ;
        grid[a][b]=1;
    }

    for(int i = 1 ; i <= 1000 ;i++){
        int x = i , y = 1 , cnt = 0;
        while(valid(x,y)){
            cnt+=grid[x][y];
            x++;y++;
        }
        ans += (cnt*(cnt-1)/2);
    }
    for(int i = 2 ; i <= 1000 ;i++){
        int x = 1 , y = i , cnt = 0;
        while(valid(x,y)){
            cnt+=grid[x][y];
            x++;y++;
        }
        ans += (cnt*(cnt-1)/2);
    }
    for(int i = 1 ; i <= 1000 ;i++){
        int x = i , y = 1 , cnt = 0;
        while(valid(x,y)){
            cnt+=grid[x][y];
            x--;y++;
        }
        ans += (cnt*(cnt-1)/2);
    }
    for(int i = 2 ; i <= 1000 ;i++){
        int x = 1000 , y = i , cnt = 0;
        while(valid(x,y)){
            cnt+=grid[x][y];
            x--;y++;
        }
        ans += (cnt*(cnt-1)/2);
    }
    cout << ans << endl;
}
