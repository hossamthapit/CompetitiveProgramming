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

char ar[3][3];
int xWin = 0 , oWin = 0 , x = 0 , o = 0 ;

void solve(){

    for(int i = 0 ; i < 3 ;i++){
        int sum = 1 ;
        for(int k = 1 ; k < 3 ;k++){
            if(ar[i][k]==ar[i][k-1])sum++;
            if(sum==3&&ar[i][k]=='O')oWin = 1;
            if(sum==3&&ar[i][k]=='X')xWin = 1;
        }
        sum = 1 ;
        for(int k = 1 ; k < 3 ;k++){
            if(ar[k][i]==ar[k-1][i])sum++;
            if(sum==3&&ar[k][i]=='O')oWin = 1;
            if(sum==3&&ar[k][i]=='X')xWin = 1;
        }
        if(ar[0][0]==ar[1][1]&&ar[1][1]==ar[2][2]&&ar[1][1]=='X')xWin = 1;
        if(ar[0][0]==ar[1][1]&&ar[1][1]==ar[2][2]&&ar[1][1]=='O')oWin = 1;
        if(ar[0][2]==ar[1][1]&&ar[1][1]==ar[2][0]&&ar[1][1]=='X')xWin = 1;
        if(ar[0][2]==ar[1][1]&&ar[1][1]==ar[2][0]&&ar[1][1]=='O')oWin = 1;
    }
}


int main()
{
    file();

    int t ;
    cin >> t ;
    while(t--){
        xWin = 0 , oWin = 0 , x = 0 , o = 0 ;
        for(int i = 0 ; i < 3 ; i++)
            for(int k = 0 ; k < 3 ;k++){
                cin >> ar[i][k];
                x += (ar[i][k]=='X');
                o += (ar[i][k]=='O');
            }

        solve();
        if(!oWin&&!xWin&&(x-o==1||x-o==0))cout << "yes" << endl;
        else if(!oWin&&xWin&&x-o==1)cout << "yes" << endl;
        else if(oWin&&!xWin&&x==o)cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
